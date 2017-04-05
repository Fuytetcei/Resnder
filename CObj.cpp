
#include "CObj.h"

// Constructores
CObj::CObj(){
    this->pos = NULL;
}

CObj::CObj(SDL_Rect* rect){
    this->pos = rect;
    this->type = OBJ_OBJ;
}

// Destructor
CObj::~CObj(){
    delete this->pos;
}

int CObj::getType(){
    return this->type;
}

SDL_Rect* CObj::getrect(){
    return this->pos;
}