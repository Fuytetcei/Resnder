
#include "CGate.h"

// Constructor
CGate::CGate(SDL_Rect *r, int dirA, int o, int codeA) : CObj(){
    // Guardo la dirección a la que apunta
    this->dir = dirA;
    // Guardo la localización de la puerta
    this->pos = r;
    // Guerdo la orientación
    this->orientation = o;
    // Guardo el código
    this->code = codeA;
    // Guardo el tipo
    this->type = OBJ_GATE;
}
// Destructor
CGate::~CGate(){
    delete this->pos;
}
// Devulvo el rectángulo
SDL_Rect* CGate::getRect(){
    return this->pos;
}
// Devuelvo la dirección a la que apunta
int CGate::getDir(){
    return this->dir;
}
// Devuelve el código al que apunta la puerta
int CGate::getCode(){
    return this->code;
}
// Devuelve el tipo de puerta
int CGate::getOrientation(){
    return this->orientation;
}