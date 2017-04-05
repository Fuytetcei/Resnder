
#include "CPlayer.h"

// Constructor y destructor
CPlayer::CPlayer(){
    // Variables de control e imágen
    //this->img = NULL;
    this->model = NULL;
    this->joy = NULL;
    this->x = 0;
    this->y = 0;
    this->xMax = 0;
    this->yMax = 0;
    this->keyState = SDL_GetKeyboardState(NULL);
    this->efecto = false;
    this->inmortal = false;
    this->time = new CTimer();

    // Variables del juego
    life = 100;

    // Otras inicializaciones
    this->canMove[UP]=false;
    this->canMove[DOWN]=false;
    this->canMove[LEFT]=false;
    this->canMove[RIGHT]=false;

    // Direción inicial
    this->dir = DIR_UP;

    // Inicio los efectos pendientes
    for(int i=0;i<EFFECT_NUMEFFECT;i++){
        this->enem[i] = NULL;
    }
}
CPlayer::~CPlayer(){
        SDL_JoystickClose(this->joy);
        delete this->time;
        //delete this->img;
        delete this->model;
}

// Inicialkizo jugador
bool CPlayer::Init(int xIni, int yIni, int xRes, int yRes, char *dir, SDL_Renderer *ren, CScenery *scn){

    //std::string aux = "obj/Player/"+this->getImgFromDir();

    // Guardo el escenario actual
    this->currScenery = scn;

    // Cargo el modelo
    this->model = new CModel2D();
    if(!this->model->Init(this->dir, ren)){
        std::cout<<"Error al cargar modelo.\n";
        return false;
    }
    
    // Posición inicial del jugador con respecto al la pantalla física
    this->x = xIni-this->currScenery->getXPos();
    this->y = yIni-this->currScenery->getYPos();
    // Guardo la pocición con respecto al escenario para mirar bien las colisiones
    this->xScn = xIni;
    this->yScn = yIni;

    // Limito con el tamaño de la imagen del jugador
    this->xMin = xRes/4;
    this->yMin = yRes/4;
    this->xMax = xRes-(xRes/4);
    this->yMax = yRes-(yRes/4);
    std::cout<<xMax<<" "<<yMax<<"\n";

    // Miro si hay mandos conectados
    if(SDL_NumJoysticks() < 1)
        std::cout<<"No hay ningun mando conectado.\n";
    else{
        std::cout<<"Hay algun mando conectado.\n";
        this->joy = SDL_JoystickOpen(0);
        if(this->joy == NULL){
            std::cout<<"Error al cargar joystcik.\n";
            return false;
        }
    }

    return true;
}

// Actualizar jugador
void CPlayer::update_Player(){
    // Miro si hay colisión con algún enemigo
    this->checkEnemies();
    // Muevo el jugador
    this->move_Player();
    // Actualizo la posición en textura
    this->model->getCurrent()->get_Rect()->x = this->x;
    this->model->getCurrent()->get_Rect()->y = this->y;
    // Actualizar vida
    // Actualizar imagen
}

// Compruebo el teclado
void CPlayer::checkKeyboard(){
    this->model->next();
    if(this->keyState[SDL_SCANCODE_A] && this->keyState[SDL_SCANCODE_S]){
        this->moveDown();
        this->moveLeft();
        if(this->dir != DIR_DOWN_LEFT){
            this->model->OnDirectionChange(DIR_DOWN_LEFT);
            this->dir = DIR_DOWN_LEFT;
        }
        return;
    }
    if(this->keyState[SDL_SCANCODE_A] && this->keyState[SDL_SCANCODE_W]){
        this->moveLeft();
        this->moveUp();
        if(this->dir != DIR_UP_LEFT){
            this->model->OnDirectionChange(DIR_UP_LEFT);
            this->dir = DIR_UP_LEFT;
        }
        return;
    }
    if(this->keyState[SDL_SCANCODE_S] && this->keyState[SDL_SCANCODE_D]){
        this->moveRight();
        this->moveDown();
        if(this->dir != DIR_DOWN_RIGHT){
            this->model->OnDirectionChange(DIR_DOWN_RIGHT);
            this->dir = DIR_DOWN_RIGHT;
        }
        return;
    }
    if(this->keyState[SDL_SCANCODE_D] && this->keyState[SDL_SCANCODE_W]){
        this->moveRight();
        this->moveUp();
        if(this->dir != DIR_UP_RIGHT){
            this->model->OnDirectionChange(DIR_UP_RIGHT);
            this->dir = DIR_UP_RIGHT;
        }
        return;
    }
    if(this->keyState[SDL_SCANCODE_A]){
        this->moveLeft();
        if(this->dir != DIR_LEFT){
            this->model->OnDirectionChange(DIR_LEFT);
            this->dir = DIR_LEFT;
        }
        return;
    }
    if(this->keyState[SDL_SCANCODE_S]){
        this->moveDown();
        if(this->dir != DIR_DOWN){
            this->model->OnDirectionChange(DIR_DOWN);
            this->dir = DIR_DOWN;
        }
        return;
    }
    if(this->keyState[SDL_SCANCODE_D]){
        this->moveRight();
        if(this->dir != DIR_RIGHT){
            this->model->OnDirectionChange(DIR_RIGHT);
            this->dir = DIR_RIGHT;
        }
        return;
    }
    if(this->keyState[SDL_SCANCODE_W]){
        this->moveUp();
        if(this->dir != DIR_UP){
            this->model->OnDirectionChange(DIR_UP);
            this->dir = DIR_UP;
        }
        return;
    }

    if(this->dir != DIR_STATIC){
        this->model->OnDirectionChange(DIR_STATIC);
        this->dir = DIR_STATIC;
    }
}
// Compruebo el joystick
void CPlayer::checkJoystick(){
    Uint8 h;
    Sint16 xAxis, yAxis;

    h = SDL_JoystickGetHat(joy, 0);
    switch(h){
        case SDL_HAT_DOWN:
            this->moveDown();
            if(this->dir != DIR_DOWN){
                this->model->OnDirectionChange(DIR_DOWN);
                this->dir = DIR_DOWN;
            }
            return;
        case SDL_HAT_UP:
            this->moveUp();
            if(this->dir != DIR_UP){
                this->model->OnDirectionChange(DIR_UP);
                this->dir = DIR_UP;
        }
            return;
        case SDL_HAT_LEFT:
            this->moveLeft();
            if(this->dir != DIR_LEFT){
                this->model->OnDirectionChange(DIR_LEFT);
                this->dir = DIR_LEFT;
        }
            return;
        case SDL_HAT_RIGHT:
            this->moveRight();
            if(this->dir != DIR_RIGHT){
                this->model->OnDirectionChange(DIR_RIGHT);
                this->dir = DIR_RIGHT;
        }
            return;
        case SDL_HAT_LEFTDOWN:
            this->moveLeft();
            this->moveDown();
            if(this->dir != DIR_DOWN_LEFT){
                this->model->OnDirectionChange(DIR_DOWN_LEFT);
                this->dir = DIR_DOWN_LEFT;
        }
            return;
        case SDL_HAT_RIGHTDOWN:
            this->moveDown();
            this->moveRight();
            if(this->dir != DIR_DOWN_RIGHT){
                this->model->OnDirectionChange(DIR_DOWN_RIGHT);
                this->dir = DIR_DOWN_RIGHT;
        }
            return;
        case SDL_HAT_LEFTUP:
            this->moveUp();
            this->moveLeft();
            if(this->dir != DIR_UP_LEFT){
                this->model->OnDirectionChange(DIR_UP_LEFT);
                this->dir = DIR_UP_LEFT;
        }
            return;
        case SDL_HAT_RIGHTUP:
            this->moveUp();
            this->moveRight();
            if(this->dir != DIR_UP_RIGHT){
                this->model->OnDirectionChange(DIR_UP_RIGHT);
                this->dir = DIR_UP_RIGHT;
        }
            return;
    }
    // Joystick izquierdo
    xAxis = SDL_JoystickGetAxis(joy, 0);
    yAxis = SDL_JoystickGetAxis(joy, 1);
    if((xAxis > 10) && (yAxis > 10)){
        this->moveRight();
        this->moveDown();
        if(this->dir != DIR_DOWN_RIGHT){
            this->model->OnDirectionChange(DIR_DOWN_RIGHT);
            this->dir = DIR_DOWN_RIGHT;
        }
        return;
    }
    if((xAxis < (-10)) && (yAxis < (-10))){
        this->moveUp();
        this->moveLeft();
        if(this->dir != DIR_UP_LEFT){
            this->model->OnDirectionChange(DIR_UP_LEFT);
            this->dir = DIR_UP_LEFT;
        }
        return;
    }
    if((xAxis > 10) && (yAxis < (-10))){
        this->moveRight();
        this->moveUp();
        if(this->dir != DIR_UP_RIGHT){
            this->model->OnDirectionChange(DIR_UP_RIGHT);
            this->dir = DIR_UP_RIGHT;
        }
        return;
    }
    if((xAxis < (-10)) && (yAxis > 10)){
        this->moveLeft();
        this->moveDown();if(this->dir != DIR_DOWN_LEFT){
            this->model->OnDirectionChange(DIR_DOWN_LEFT);
            this->dir = DIR_DOWN_LEFT;
        }
        return;
    }
    if((xAxis > 0) && (yAxis == 0)){
        this->moveRight();
        if(this->dir != DIR_RIGHT){
            this->model->OnDirectionChange(DIR_RIGHT);
            this->dir = DIR_RIGHT;
        }
        return;
    }
    if((xAxis < (-10)) && (yAxis == 0)){
        this->moveLeft();
        if(this->dir != DIR_LEFT){
            this->model->OnDirectionChange(DIR_LEFT);
            this->dir = DIR_LEFT;
        }
        return;
    }
    if((xAxis == 0) && (yAxis < (-10))){
        this->moveUp();
        if(this->dir != DIR_UP){
            this->model->OnDirectionChange(DIR_UP);
            this->dir = DIR_UP;
        }
        return;
    }
    if((xAxis == 0) && (yAxis > 0)){
        this->moveDown();
        if(this->dir != DIR_DOWN){
            this->model->OnDirectionChange(DIR_DOWN);
            this->dir = DIR_DOWN;
        }
        return;
    }
    // Joystick derecho
    xAxis = SDL_JoystickGetAxis(joy, 2);
    yAxis = SDL_JoystickGetAxis(joy, 3);
}
// Comprueba si algún enemigo ha causado algún efecto
void CPlayer::checkEnemies(){
    // Miro si hay algún efecto recibido
    if(efecto){
        if(this->enem[EFFECT_CURE]!=NULL){
            this->enem[EFFECT_CURE]=NULL;
        }
        if(this->enem[EFFECT_DAMAGE]!=NULL){
            // Aplico el daño
            this->life -= this->enem[EFFECT_DAMAGE]->getDamage();
            // Me hago inmortal
            this->inmortal = true;
            // Programo un timer para volver a ser mortal
            this->time->setTime(5);
            // Desanoto al enemigo
            this->enem[EFFECT_DAMAGE]=NULL;
        }
        if(this->enem[EFFECT_POISSON]!=NULL){
            this->enem[EFFECT_POISSON]==NULL;
        }
        if(this->enem[EFFECT_LESSDEFENSE]!=NULL){
            this->enem[EFFECT_LESSDEFENSE]=NULL;
        }
        if(this->enem[EFFECT_MOREDEFENSE]!=NULL){
            this->enem[EFFECT_MOREDEFENSE]=NULL;
        }
        if(this->enem[EFFECT_LESDAMAGE]!=NULL){
            this->enem[EFFECT_LESDAMAGE]=NULL;
        }
        if(this->enem[EFFECT_MOREDAMAGE]!=NULL){
            this->enem[EFFECT_MOREDAMAGE]=NULL;
        }
        if(this->enem[EFFECT_BURNED]!=NULL){
            this->enem[EFFECT_BURNED]=NULL;
        }
        if(this->enem[EFFECT_FROZEN]!=NULL){
            this->enem[EFFECT_FROZEN]=NULL;
        }
        this->inmortal = true;
    }
    this->efecto = false;
}
// Registra un efecto sobre el jugador
void CPlayer::hitPlayer(int i, CEnemy *enem){
    // Miro si soy inmortal
    if(this->inmortal){
         // Miro si ha acabado el timer
        if(!this->time->isActivated()){
            this->inmortal = false;
        }
        return;
    }
    // Anoto quien ha provocado el efecto
    this->enem[i] = enem;
    // Anoto que hay algún efecto pendiente
    this->efecto = true;
}
// Actualiza la posición del jugador
void CPlayer::move_Player(){
    // Miro el teclado
    checkKeyboard();
    // Miro el joystick
    checkJoystick();
}
// Muevo al jugador o la pantalla en una dirección
void CPlayer::moveDown(){
    checkColisionDown();
    if(this->canMove[DOWN]){
        if(this->y < this->yMax){
            this->y++;
        }
        else
            this->currScenery->moveDown();
        this->yScn++;
    }
    this->canMove[DOWN] = false;
    
}
void CPlayer::moveRight(){
    checkColisionRight();
    if(this->canMove[RIGHT]){
        if(this->x < this->xMax)
            this->x++;
        else
            this->currScenery->moveRight();
        this->xScn++;
    }
    this->canMove[RIGHT] = false;
}
void CPlayer::moveLeft(){
    checkColisionLeft();
    if(this->canMove[LEFT]){
        if(this->x >= this->xMin)
            this->x--;
        else
            this->currScenery->moveLeft();
        this->xScn--;
    }
    this->canMove[LEFT] = false;
}
void CPlayer::moveUp(){
    checkColisionUp();
    if(this->canMove[UP]){
        if(this->y >= this->yMin)
            this->y--;
        else
            this->currScenery->moveUp();
        this->yScn--;
    }
    this->canMove[UP] = false;
}

void CPlayer::checkColisionUp(){
    int n;
    SDL_Rect *r;
    CGate *aux;

    // Obtengo el número de objetos del escenario
    n = this->currScenery->getNumRect();
    // Miro cada rectangulo del escenario actual
    for(int i=0;i<n;i++){
        r = this->currScenery->get_Rect(i);
        // Miro si puedo ir arriba
        if((this->xScn >= (r->x)) && (this->xScn <= r->x+r->w) && (this->yScn-1 <= r->y+r->h) && (this->yScn-1 >= r->y)) {
            this->canMove[UP] = false;
            return;
        }
        else {
            this->canMove[UP] = true;
        }
        if((this->xScn+32 >= r->x) && (this->xScn+32 <= r->x+r->w) && (this->yScn-1 <= r->y+r->h) && (this->yScn-1 >= r->y)) {
            this->canMove[UP] = false;
            return;
        }
        else {
            this->canMove[UP] = true;
        }
    }

    // Miro colisiones con las puertas
    // Obtengo el número de objetos del escenario
    n = this->currScenery->getNumGates();
    // --------------------------------------------------------------------------------------------------------
    // Miro cada rectangulo del escenario actual
    for(int j=0;j<n;j++){
        aux = this->currScenery->getkGate(j);
        r = aux->getRect();
        // Miro si puedo ir arriba
        if((this->xScn >= (r->x)) && (this->xScn <= r->x+r->w) && (this->yScn-1 <= r->y+r->h) && (this->yScn-1 >= r->y)) {
            // Genero evento para cambiar el escenario
            this->pushUserEvent(aux);
            this->canMove[UP] = false;
            return;
        }
        else {
            this->canMove[UP] = true;
        }
        if((this->xScn+32 >= r->x) && (this->xScn+32 <= r->x+r->w) && (this->yScn-1 <= r->y+r->h) && (this->yScn-1 >= r->y)) {
            // Genero evento para cambiar el escenario
            this->pushUserEvent(aux);
            this->canMove[UP] = false;
            return;
        }
        else {
            this->canMove[UP] = true;
        }
    }
}
void CPlayer::checkColisionDown(){
    int n;
    SDL_Rect *r;
    CGate *aux;

    // Obtengo el número de objetos del escenario
    n = this->currScenery->getNumRect();
    // Miro cada rectangulo del escenario actual
    for(int i=0;i<n;i++){
        r = this->currScenery->get_Rect(i);
        // Miro si puedo ir abajo
        if((this->xScn >= r->x) && (this->xScn <= r->x+r->w) && (this->yScn+33 >= r->y) && (this->yScn+33 <= r->y+r->h)){
            this->canMove[DOWN] = false;
            return;
        }
        else {
            this->canMove[DOWN] = true;
        }
        if((this->xScn+32 >= r->x) && (this->xScn+32 <= r->x+r->w) && (this->yScn+33 >= r->y) && (this->yScn+33 <= r->y+r->h)) {
            this->canMove[DOWN] = false;
            return;
        }
        else {
            this->canMove[DOWN] = true;
        }
    }

    // Miro las puertas
    n = this->currScenery->getNumGates();
    // Miro cada rectangulo del escenario actual
    for(int j=0;j<n;j++){
        aux = this->currScenery->getkGate(j);
        r = aux->getRect();
        // Miro si puedo ir abajo
        if((this->xScn >= r->x) && (this->xScn <= r->x+r->w) && (this->yScn+33 >= r->y) && (this->yScn+33 <= r->y+r->h)){
            this->pushUserEvent(aux);
            this->canMove[DOWN] = false;
            return;
        }
        else {
            this->canMove[DOWN] = true;
        }
        if((this->xScn+32 >= r->x) && (this->xScn+32 <= r->x+r->w) && (this->yScn+33 >= r->y) && (this->yScn+33 <= r->y+r->h)) {
            this->pushUserEvent(aux);
            this->canMove[DOWN] = false;
            return;
        }
        else {
            this->canMove[DOWN] = true;
        }
    }
}
void CPlayer::checkColisionRight(){
    int n;
    SDL_Rect *r;
    CGate *aux;

    // Obtengo el número de objetos del escenario
    n = this->currScenery->getNumRect();
    // Miro cada rectangulo del escenario actual
    for(int i=0;i<n;i++){
        r = this->currScenery->get_Rect(i);
        // Miro si puedo ir a la derecha
        if((this->yScn >= r->y) && (this->yScn <= r->y+r->h) && (this->xScn+33 >= r->x) && (this->xScn+33 <= r->x+r->w)) {
            this->canMove[RIGHT] = false;
            return;
        }
        else {
            this->canMove[RIGHT] = true;
        }
        if((this->yScn+32 >= r->y) && (this->yScn+32 <= r->y+r->h) && (this->xScn+33 >= r->x) && (this->xScn+33 <= r->x+r->w)) {
            this->canMove[RIGHT] = false;
            return;
        }
        else {
            this->canMove[RIGHT] = true;
        }
    }

    // Miro las puertas
    // Obtengo el número de objetos del escenario
    n = this->currScenery->getNumGates();
    // Miro cada rectangulo del escenario actual
    for(int j=0;j<n;j++){
        aux = this->currScenery->getkGate(j);
        r = aux->getRect();
        // Miro si puedo ir a la derecha
        if((this->yScn >= r->y) && (this->yScn <= r->y+r->h) && (this->xScn+33 >= r->x) && (this->xScn+33 <= r->x+r->w)) {
            this->pushUserEvent(aux);
            this->canMove[RIGHT] = false;
            return;
        }
        else {
            this->canMove[RIGHT] = true;
        }
        if((this->yScn+32 >= r->y) && (this->yScn+32 <= r->y+r->h) && (this->xScn+33 >= r->x) && (this->xScn+33 <= r->x+r->w)) {
            this->pushUserEvent(aux);
            this->canMove[RIGHT] = false;
            return;
        }
        else {
            this->canMove[RIGHT] = true;
        }
    }
}
void CPlayer::checkColisionLeft(){
    int n;
    SDL_Rect *r;
    CGate *aux;

    // Obtengo el número de objetos del escenario
    n = this->currScenery->getNumRect();
    // Miro cada rectangulo del escenario actual
    for(int i=0;i<n;i++){
        r = this->currScenery->get_Rect(i);
        // Miro si puedo ir a la izquierda
        if((this->yScn >= r->y) && (this->yScn <= r->y+r->h) && (this->xScn-1 <= r->x+r->w) && (this->xScn-1 >= r->x)) {
            this->canMove[LEFT] = false;
            return;
        }
        else {
            this->canMove[LEFT] = true;
        }
        if((this->yScn+32 >= r->y) && (this->yScn+32 <= r->y+r->h) && (this->xScn-1 <= r->x+r->w) && (this->xScn-1 >= r->x)) {
            this->canMove[LEFT] = false;
            return;
        }
        else {
            this->canMove[LEFT] = true;
        }
    }

    // MIro las puertas
    // Obtengo el número de objetos del escenario
    n = this->currScenery->getNumGates();
    // Miro cada rectangulo del escenario actual
    for(int j=0;j<n;j++){
        aux = this->currScenery->getkGate(j);
        r = aux->getRect();
        // Miro si puedo ir a la izquierda
        if((this->yScn >= r->y) && (this->yScn <= r->y+r->h) && (this->xScn-1 <= r->x+r->w) && (this->xScn-1 >= r->x)) {
            this->pushUserEvent(aux);
            this->canMove[LEFT] = false;
            return;
        }
        else {
            this->canMove[LEFT] = true;
        }
        if((this->yScn+32 >= r->y) && (this->yScn+32 <= r->y+r->h) && (this->xScn-1 <= r->x+r->w) && (this->xScn-1 >= r->x)) {
            this->pushUserEvent(aux);
            this->canMove[LEFT] = false;
            return;
        }
        else {
            this->canMove[LEFT] = true;
        }
    }
}

// Devuelve parámetros
int CPlayer::getXScn(){
    return this->xScn;
}
int CPlayer::getYScn(){
    return this->yScn;
}
int CPlayer::getLife(){
    return this->life;
}
SDL_Texture* CPlayer::get_Tex(){
    return this->model->getCurrent()->get_Tex();
}
SDL_Rect* CPlayer::get_Rect(){
    return this->model->getCurrent()->get_Rect();
}
SDL_Rect* CPlayer::get_Img_Rect(){
    return this->model->getCurrentRect();
}

// Funciones sobre eventos
void CPlayer::pushUserEvent(CGate *g){
    SDL_Event *e = new SDL_Event();
    e->user.type = USER_EVENTS;
    e->user.code = SCENERYCHANGE;
    e->user.data1 = (void*)g;
    SDL_PushEvent(e);
}
void CPlayer::OnNewScenery(CGate* g, CScenery *scn){
    int a = g->getOrientation();
    SDL_Rect *r = g->getRect();

    // Miro en que dirección me debo situar
    switch(a){
        case UP:
            this->xScn = r->x+(r->w/2);
            this->x = scn->getXPos()+this->xScn;
            this->yScn = r->y-this->model->getHeight()-1;
            this->y = scn->getYPos()+this->yScn;
            break;
        case DOWN:
            this->xScn = r->x+(r->w/2);
            this->x = scn->getXPos()+this->xScn;
            this->yScn = r->y+r->h+1;
            this->y = scn->getYPos()+this->yScn;
            break;
        case RIGHT:
            this->xScn = r->x+r->w+1;
            this->x = scn->getXPos()+this->xScn;
            this->yScn = r->y+(r->h/2);
            this->y = scn->getYPos()+this->yScn;
            break;
        case LEFT:
            this->xScn = r->x-this->model->getWidth()-1;
            this->x = scn->getXPos()+this->xScn;
            this->yScn = r->y+(r->h/2);
            this->y = scn->getYPos()+this->yScn;
            break;
        default:
            break;
    }
    // Guardo el nuevo escenario
    this->currScenery = scn;
}

// Funciones auxiliares
std::string CPlayer::getImgFromDir(){
    switch(this->dir){
        case DIR_UP:
            return "up.png";
        case DIR_DOWN:
            return "down.png";
        case DIR_LEFT:
            return "left.png";
        case DIR_RIGHT:
            return "right.png";
        case DIR_UP_LEFT:
            return "up_left.png";
        case DIR_UP_RIGHT:
            return "up_right.png";
        case DIR_DOWN_LEFT:
            return "down_left.png";
        case DIR_DOWN_RIGHT:
            return "down_right.png";
        default:
            break;
    }
    return "";
}