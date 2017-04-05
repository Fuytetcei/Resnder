
#ifndef _CGATE_H
#define _CGATE_H

#include "CBasics.h"
#include "CObj.h"

class CGate : CObj{
    private:
        int orientation, dir, code;// ............................... Dirección del escenario al que apunta
                                   //-------------------------------- Hacia donde apunta la puerta
                                   // ............................... Código que identifica las puertas de dos escenarios
    public:
        CGate(SDL_Rect *r, int dirA, int o, int codeA);
        ~CGate();
        SDL_Rect* getRect();
        int getDir();
        int getCode();
        int getOrientation();
};

#endif

