
#include "CCartel.h"

// Constructor
CCartel::CCartel(SDL_Rect* rect, char *dir):CObj(rect){
    this->type = OBJ_CARTEL;
}
// Destructor
CCartel::~CCartel(){
}
// Devuelvo el texto
std::string CCartel::getText(){
    return this->text;
}