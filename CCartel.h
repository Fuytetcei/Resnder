
#ifndef CCARTEL_H
#define CCARTEL_H

#include "CBasics.h"

class CCartel : CObj{
    private:
        std::string text;
    public:
        CCartel(SDL_Rect* rect, char *dir);
        ~CCartel();
        std::string getText();
};

#endif

