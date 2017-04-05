
#ifndef _OBJ_H
#define _OBJ_H

#include "CBasics.h"

class CObj{
    protected:
        int type;
        SDL_Rect *pos;
    public:
        CObj();
        CObj(SDL_Rect *rect);
        ~CObj();
        int getType();
        SDL_Rect* getrect();
};

#endif

