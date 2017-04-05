
#include "CScenery.h"

// Constructor
CScenery::CScenery(SDL_Renderer *ren){
    this->n = 0;
    this->image = new CImage(ren);
}
// Destructor
CScenery::~CScenery(){
    for(int i=0;i<this->n;i++){
        delete this->posRect[i];
    }
    free(posRect);
    delete this->image;
}
// Inicialización
bool CScenery::Init(int code, int xIni, int yIni){

    char aux[200];
    int a, b, c;
    sqlite3 *db;
    sqlite3_stmt *selectStmt;
    int s, i;
    std::string dir;

    memset(aux, '\0', 200);
    if(!this->image){
        std::cout<<"Error al crear CImage del escenario\n";
        return false;
    }
    // Abrir conexión con la BDD
    if(sqlite3_open("segundo_juegoBDD.db", &db) != SQLITE_OK){
        std::cout<<"Error al abrir base de datos\n";
        return false;
    }
    // Cargo la dirección del escenario
    sprintf(aux, "select * from CScenery where idCScenery == %d;", code);
    sqlite3_prepare(db, aux, strlen(aux)+1, &selectStmt, NULL);
    s = sqlite3_step (selectStmt);
    dir.append((char*)sqlite3_column_text(selectStmt, 1));

    if(!this->image->Init("scenery/"+dir+".bmp", xIni, yIni)) {
        std::cout<<"Error al cargar imagen de escenario.\n";
        return false;
    }

    // Guardo la posición inicial
    this->posX = xIni;
    this->posY = yIni;
    this->type = 13;

    // Cargo los datos del escenario
    // Calculo el número de rectángulos
    sqlite3_finalize(selectStmt);
    sprintf(aux, "select count(idObstacle) from CObstacle where idCScenery == %d;", code);
    sqlite3_prepare(db, aux, strlen(aux)+1, &selectStmt, NULL);
    s = sqlite3_step (selectStmt);
    this->n = sqlite3_column_int(selectStmt, 0);

    // Reservo memoria
    this->posRect = (CObj**)malloc(sizeof(CObj)*(this->n+this->getTypeNum()));

    // Cargo los rectángulos
    sqlite3_finalize(selectStmt);
    sprintf(aux, "select * from CObstacle where idCScenery == %d;", code);
    sqlite3_prepare(db, aux, strlen(aux)+1, &selectStmt, NULL);
    SDL_Rect *rectAux;

    i=0;
    while (1) {
        // Busco la siguiente línea
        s = sqlite3_step (selectStmt);
        if (s == SQLITE_ROW) {
            rectAux = new SDL_Rect();
            rectAux->x = sqlite3_column_int(selectStmt, 2);
            rectAux->y = sqlite3_column_int(selectStmt, 3);
            rectAux->w = sqlite3_column_int(selectStmt, 4);
            rectAux->h = sqlite3_column_int(selectStmt, 5);
            this->posRect[i] = new CObj(rectAux);
            i++;
        }
        else if (s == SQLITE_DONE) {
            break;
        }
        else {
            std::cout<<"Error al leer\n";
            sqlite3_close(db);
            return  false;
        }
    }

    // Cargo las puertas
    // Calculo el número de rectángulos
    sqlite3_finalize(selectStmt);
    sprintf(aux, "select count(idCGate) from CGate where currCScenery == %d;", code);
    sqlite3_prepare(db, aux, strlen(aux)+1, &selectStmt, NULL);
    s = sqlite3_step (selectStmt);
    this->g = sqlite3_column_int(selectStmt, 0);

    // Reservo memoria
    this->gates = (CGate**)malloc(sizeof(CGate*)*g);

    sqlite3_finalize(selectStmt);
    sprintf(aux, "select * from CGate where currCScenery == %d;", code);
    sqlite3_prepare(db, aux, strlen(aux)+1, &selectStmt, NULL);

    i=0;
    while (1) {
        // Busco la siguiente línea
        s = sqlite3_step (selectStmt);
        if (s == SQLITE_ROW) {
            // Cargo rectangulo
            rectAux = new SDL_Rect();
            rectAux->x = sqlite3_column_int(selectStmt, 5);
            rectAux->y = sqlite3_column_int(selectStmt, 6);
            rectAux->w = sqlite3_column_int(selectStmt, 7);
            rectAux->h = sqlite3_column_int(selectStmt, 8);

            // Escenario al que apunta
            b = sqlite3_column_int(selectStmt, 2);
            // Dirección
            a = sqlite3_column_int(selectStmt, 4);
            // Código
            c = sqlite3_column_int(selectStmt, 3);

            this->gates[i] = new CGate(rectAux, b, a, c);

            i++;
        }
        else if (s == SQLITE_DONE) {
            break;
        }
        else {
            std::cout<<"Error al leer\n";
            sqlite3_close(db);
            return  false;
        }
    }
    
    // Cierro conexión con la BDD
    sqlite3_finalize(selectStmt);
    sqlite3_close(db);

    // Añado las paredes
    addWall();

    return true;
}

// Devuelvo el rectángulo solicitado
SDL_Rect* CScenery::get_Rect(int i){
    if(i<this->n+this->getTypeNum())
        return this->posRect[i]->getrect();
    return NULL;
}

// Devuelvo el rectángulo de pintado del escenario
SDL_Rect* CScenery::get_Rect(){
    return this->image->get_Rect();
}
// Devulvo la textura del escenario
SDL_Texture* CScenery::get_Tex(){
    return this->image->get_Tex();
}
// Número de objetos del escenario
int CScenery::getNumRect(){
    return this->n+this->getTypeNum();
}
// Posición física del escenario
int CScenery::getXPos(){
    return this->posX;
}
int CScenery::getYPos(){
    return this->posY;
}

// Cambio la posición de las imágenes
void CScenery::addXPos(){
    this->posX++;
    this->image->addXpos();
}
void CScenery::substractXPos(){
    this->posX--;
    this->image->substractXpos();
}
void CScenery::addYPos(){
    this->posY++;
    this->image->addYpos();
}
void CScenery::substractYPos(){
    this->posY--;
    this->image->substractYpos();
}

// Añado las paredes de fin de mapa
void CScenery::addWall(){
    switch(this->type){
        case 0:
            this->posRect[this->n] = new CObj(getTopRect());
            this->posRect[this->n+1] = new CObj(getLeftRect());
            break;
        case 1:
            this->posRect[this->n] = new CObj(getTopRect());
            break;
        case 2:
            this->posRect[this->n] = new CObj(getTopRect());
            this->posRect[this->n+1] = new CObj(getRightRect());
            break;
        case 3:
            this->posRect[this->n] = new CObj(getLeftRect());
            break;
        case 5:
            this->posRect[this->n] = new CObj(getRightRect());
            break;
        case 6:
            this->posRect[this->n] = new CObj(getLeftRect());
            this->posRect[this->n+1] = new CObj(getBottomRect());
            break;
        case 7:
            this->posRect[this->n] = new CObj(getBottomRect());
            break;
        case 8:
            this->posRect[this->n] = new CObj(getBottomRect());
            this->posRect[this->n+1] = new CObj(getRightRect());
            break;
        case 9:
            this->posRect[this->n] = new CObj(getTopRect());
            this->posRect[this->n+1] = new CObj(getRightRect());
            this->posRect[this->n+2] = new CObj(getLeftRect());
            break;
        case 10:
            this->posRect[this->n] = new CObj(getTopRect());
            this->posRect[this->n+2] = new CObj(getBottomRect());
            this->posRect[this->n+1] = new CObj(getLeftRect());
            break;
        case 11:
            this->posRect[this->n] = new CObj(getBottomRect());
            this->posRect[this->n+2] = new CObj(getRightRect());
            this->posRect[this->n+1] = new CObj(getLeftRect());
            break;
        case 12:
            this->posRect[this->n+1] = new CObj(getBottomRect());
            this->posRect[this->n+2] = new CObj(getTopRect());
            this->posRect[this->n] = new CObj(getRightRect());
            break;
        case 13:
            this->posRect[this->n+1] = new CObj(getBottomRect());
            this->posRect[this->n+2] = new CObj(getTopRect());
            this->posRect[this->n] = new CObj(getRightRect());
            this->posRect[this->n+3] = new CObj(getLeftRect());
            break;
        default:
            break;
    }
}

SDL_Rect*  CScenery::getTopRect(){
    SDL_Rect *rect = new SDL_Rect();

    rect->x = 0;
    rect->y = 0;
    rect->w = this->image->get_width();
    rect->h = 2;
    return rect;
}
SDL_Rect* CScenery::getBottomRect(){
    SDL_Rect *rect = new SDL_Rect();

    rect->x = 0;
    rect->y = this->image->get_height()-2;
    rect->w = this->image->get_width();
    rect->h = 2;
    return rect;
}
SDL_Rect* CScenery::getLeftRect(){
    SDL_Rect *rect = new SDL_Rect();

    rect->x = 0;
    rect->y = 0;
    rect->w = 2;
    rect->h = this->image->get_height();
    return rect;
}
SDL_Rect* CScenery::getRightRect(){
    SDL_Rect *rect = new SDL_Rect();

    rect->x = this->image->get_width();
    rect->y = 0;
    rect->w = 2;
    rect->h = this->image->get_height();
    return rect;
}

// Devuelve el número de rectángulos de periferia
int CScenery::getTypeNum(){
    switch(this->type){
        case 0:
        case 2:
        case 6:
        case 8:
            return 2;
        case 1:
        case 3:
        case 5:
        case 7:
            return 1;
        case 4:
            return 0;
        case 10:
        case 11:
        case 12:
        case 9:
            return 3;
        case 13:
            return 4;
        default:
            return 0;
    }
}

// Para posible futuro
std::string CScenery::getTopSnc(){
    return this->topScn;
}
std::string CScenery::getBottomSnc(){
    return this->bottomScn;
}
std::string CScenery::getLeftSnc(){
    return this->leftScn;
}
std::string CScenery::getRightSnc(){
    return this->rightScn;
}

// Scroll
void CScenery::moveDown(){
    this->posY--;
    this->image->substractYpos();
}
void CScenery::moveUp(){
    this->posY++;
    this->image->addYpos();
}
void CScenery::moveLeft(){
    this->posX++;
    this->image->addXpos();
}
void CScenery::moveRight(){
    this->posX--;
    this->image->substractXpos();
}

// Funciones de puertas
int CScenery::getNumGates(){
    return this->g;
}
CGate* CScenery::getkGate(int k){
    return this->gates[k];
}
CGate* CScenery::getGate(int code){
    for(int i=0;i<this->g;i++){
        // Comparo códigos y devuelvo la puerta si coincide
        if(code == this->gates[i]->getCode())
            return this->gates[i];
    }
    return NULL;
}
void CScenery::setPos(int xPos, int yPos){
    SDL_Rect *r;
    this->posX = xPos;
    this->posY = yPos;
    r = this->image->get_Rect();
    r->x = posX;
    r->y = posY;
}

/*
 * Up: X
 * Down: Ok
 * Left: X.
 * Right: Ok.
  */