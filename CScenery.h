
#ifndef _CSCENERY_H
#define _CSCENERY_H

#include "CBasics.h"
#include "CImage.h"
#include "CObj.h"
#include "CGate.h"

class CScenery {
    private:
        int n;// ----------------------- Número de objetos del escenarios sin ninguna función
        int g;// ....................... Número de puertas
        int act;// --------------------- Número de objetos de acción
        CObj **posRect;// .............. Rectángulos de obstáculos del escenario
        CGate **gates;// --------------- Puertas de transición a otros escenarios
        int posX, posY, type;// ........ Posición del escenario
        std::string topScn, bottomScn, leftScn, rightScn;// -------- Nombre de los escenarios adyacentes
        CImage *image;

        // Funciones
        SDL_Rect* getTopRect();
        SDL_Rect* getBottomRect();
        SDL_Rect* getLeftRect();
        SDL_Rect* getRightRect();
        void addWall();
    public:
        // Funciones de inicialización y terminación
        CScenery(SDL_Renderer *ren);
        ~CScenery();
        bool Init(int code, int xIni, int yIni);// --------------- Inicializa esta poción de escenario. Recibe el nombre de la parte

        // Obtención de datos
        SDL_Rect* get_Rect(int i);// .......... Devuelve uno de los rectángulos del escenario.
        SDL_Rect* get_Rect();
        int getNumRect();
        SDL_Texture* get_Tex();
        int getXPos();
        int getYPos();
        std::string getTopSnc();
        std::string getBottomSnc();
        std::string getLeftSnc();
        std::string getRightSnc();

        // Modificación de datos
        void addXPos();
        void addYPos();
        void substractXPos();
        void substractYPos();
        // Mueve el escenario
        void moveDown();
        void moveUp();
        void moveLeft();
        void moveRight();

        int getTypeNum();// -------------------------------- Devuelve el número de paredes de periferia
        int getNumGates();// ............................... Devuelve el número de puertas
        CGate* getkGate(int k);// --------------------------- Devuelve la iésima puerta
        CGate* getGate(int code);// ............... Devuelve la puerta correspondiente al código proporcionado
        void setPos(int xPos, int yPos);
};

#endif