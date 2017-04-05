
#ifndef _CENEMY_H
#define _CENEMY_H

#include "CBasics.h"
#include "CPlayer.h"
#include "CScenery.h"

// Deshago la dependencia cíclica
class CPlayer;

class CEnemy {
    private:
        CImage *img;// ---------------------------------------- Imagen
        //CScroll *currScenery;
        CScenery* currScenery;
        CPlayer* player;
        int x, y;// ------------------------------------------- Posición
        int xMax, yMax, xMin, yMin, xScn, yScn;//.............. Posición máxima, mínima y posición en el escenario
        bool canMove[4];
        int damage;

        void checkColisionUp();
        void checkColisionDown();
        void checkColisionRight();
        void checkColisionLeft();
        void checkColisionPlayer();
        // Movimientos
        void moveUp();
        void moveDown();
        void moveRight();
        void moveLeft();
    public:
        CEnemy(CPlayer *pla);// ---------- Constructor
        ~CEnemy();// .......... Destructor
        bool Init(int xIni, int yIni, int xMax, int yMax, char *dir, SDL_Renderer *ren, CScenery *scn);// --------- Inicializar enemigo
        CImage* get_Image();// ........ Devolver imagen del enemigo
        void moveEnemy();// ----------- Actualizar posición del enemigo
        void updateEnemy();// ......... Actualizar datos de enemigo
        int getXScn();
        int getYScn();
        int getDamage();
};

#endif