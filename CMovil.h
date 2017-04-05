
/* 
 * File:   CMovil.h
 * Author: Daniel David Abellán Serrano
 *
 * Created on 1 de marzo de 2017, 20:04
 */

#ifndef CMOVIL_H
#define CMOVIL_H

#include "CBasics.h"
#include "CImage.h"

class CMovil : CObj {
    protected:
        CImage *img;
    public:
        CMovil();
        ~CMovil();
        bool Init();
        void moveUp();
        void moveDown();
        void moveLeft();
        void moveRight();
};

#endif /* CMOVIL_H */

