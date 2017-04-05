
#include "CEnemy.h"

CEnemy::CEnemy(CPlayer* pla){
    this->img = NULL;
    this->x = 0;
    this->y = 0;
    this->xMax = 0;
    this->yMax = 0;
    this->canMove[UP]=false;
    this->canMove[DOWN]=false;
    this->canMove[LEFT]=false;
    this->canMove[RIGHT]=false;
    this->player = pla;
    this->damage = 1;
}

// Destructor
CEnemy::~CEnemy(){
    delete this->img;
}

// Inicialkizo jugador
bool CEnemy::Init(int xIni, int yIni, int xMax, int yMax, char *dir, SDL_Renderer *ren, CScenery *scn){
    // Guardo el escenario actual
    this->currScenery = scn;

    // Cargo imagen
    this->img = new CImage(ren);
    if(!this->img->Init(dir, xIni, yIni)){
        std::cout<<"Error al cargar imagen de enemigo.";
        return false;
    }

    // Posición inicial del enemigo
    this->x = xIni;
    this->y = yIni;
    // Ojo esto hay que apañarlo
    this->xScn = xIni;
    this->yScn = yIni;

    // Limito con el tamaño de la imagen del enemigo
    this->xMax = xMax - this->img->get_width();
    this->yMax = yMax - this->img->get_height();

    this->img->get_Rect()->x = xIni;
    this->img->get_Rect()->y = yIni;

    return true;
}

// Devuelve la imagen correspondiente
CImage* CEnemy::get_Image(){
    return this->img;
}

// Actualiza la posición del jugador
void CEnemy::moveEnemy(){

}

// Muevo al jugador o la pantalla en una dirección
void CEnemy::moveDown(){
    checkColisionDown();
    if(this->canMove[DOWN]){
        if(this->y+this->img->get_height() < this->yMax){
            this->y++;
        }
    }
    this->canMove[DOWN] = false;
}
void CEnemy::moveRight(){
    checkColisionRight();
    if(this->canMove[RIGHT]){
        if(this->x+this->img->get_width() < this->xMax)
            this->x++;
    }
    this->canMove[RIGHT] = false;
}
void CEnemy::moveLeft(){
    checkColisionLeft();
    if(this->canMove[LEFT])
        if(this->x >= this->xMin)
            this->x--;
    this->canMove[LEFT] = false;
}
void CEnemy::moveUp(){
    checkColisionUp();
    if(this->canMove[UP]){
        if(this->y >= this->yMin)
            this->y--;
        this->yScn--;
    }
    this->canMove[UP] = false;
}

void CEnemy::updateEnemy(){
    // Muevo el enemigo
    this->moveEnemy();
    // Actualizo la posición en textura
    this->img->get_Rect()->x = this->x+this->currScenery->getXPos();
    this->img->get_Rect()->y = this->y+this->currScenery->getYPos();
    // Miro colisión con el jugador
    this->checkColisionPlayer();
    // Actualizar vida
    // Actualizar imagen
}

void CEnemy::checkColisionUp(){
    int n;
    SDL_Rect *r;

    n = this->currScenery->getNumRect()+this->currScenery->getTypeNum();
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
}
void CEnemy::checkColisionDown(){
    int n;
    SDL_Rect *r;

    n = this->currScenery->getNumRect()+this->currScenery->getTypeNum();
    // Miro cada rectangulo del escenario actual
    for(int i=0;i<n;i++){
        r = this->currScenery->get_Rect(i);
        // Miro si puedo ir abajo
        if((this->xScn >= r->x) && (this->xScn <= r->x) && (this->yScn+33 >= r->y) && (this->yScn+33 <= r->y+r->h)){
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
}
void CEnemy::checkColisionRight(){
    int n;
    SDL_Rect *r;

    n = this->currScenery->getNumRect()+this->currScenery->getTypeNum();
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
}
void CEnemy::checkColisionLeft(){
    int n;
    SDL_Rect *r;

    n = this->currScenery->getNumRect()+this->currScenery->getTypeNum();
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
}
void CEnemy::checkColisionPlayer(){
    SDL_Rect *r, *e;

    // Rectángulo del jugador
    r = this->player->get_Rect();
    // Rectángulo del enemigo
    e = this->img->get_Rect();
    // Miro a la izquierda
    if((e->y >= r->y) && (e->y <= r->y+r->h) && (e->x-1 <= r->x+r->w) && (e->x-1 >= r->x)) {
        this->player->hitPlayer(EFFECT_DAMAGE, this);
        return;
    }
    if((e->y+32 >= r->y) && (e->y+32 <= r->y+r->h) && (e->x-1 <= r->x+r->w) && (e->x-1 >= r->x)) {
        this->player->hitPlayer(EFFECT_DAMAGE, this);
        return;
    }
    // Miro a la derecha
    if((e->y >= r->y) && (e->y <= r->y+r->h) && (e->x+33 >= r->x) && (e->x+33 <= r->x+r->w)) {
        this->player->hitPlayer(EFFECT_DAMAGE, this);
        return;
    }
    if((e->y+32 >= r->y) && (e->y+32 <= r->y+r->h) && (e->x+33 >= r->x) && (e->x+33 <= r->x+r->w)) {
        this->player->hitPlayer(EFFECT_DAMAGE, this);
        return;
    }
    // Miro arriba
    if((e->x >= (r->x)) && (e->x <= r->x+r->w) && (e->y-1 <= r->y+r->h) && (e->y-1 >= r->y)) {
        this->player->hitPlayer(EFFECT_DAMAGE, this);
        return;
    }
    if((e->x+32 >= r->x) && (e->x+32 <= r->x+r->w) && (e->y-1 <= r->y+r->h) && (e->y-1 >= r->y)) {
        this->player->hitPlayer(EFFECT_DAMAGE, this);
        return;
    }
    // Mirp abajo
    if((e->x >= r->x) && (e->x <= r->x) && (e->y+33 >= r->y) && (e->y+33 <= r->y+r->h)){
        this->player->hitPlayer(EFFECT_DAMAGE, this);
        return;
    }
    if((e->x+32 >= r->x) && (e->x+32 <= r->x+r->w) && (e->y+33 >= r->y) && (e->y+33 <= r->y+r->h)) {
        this->player->hitPlayer(EFFECT_DAMAGE, this);
        return;
    }
}

int CEnemy::getXScn(){
    return this->xScn;
}
int CEnemy::getYScn(){
    return this->yScn;
}

// Efectos hacia el jugador
int CEnemy::getDamage(){
    return this->damage;
}