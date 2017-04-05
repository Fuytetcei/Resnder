
#ifndef _CPLAYER_H
#define _CPLAYER_H

#include "CBasics.h"
#include "CTimer.h"
#include "CImage.h"
#include "CModel2D.h"
#include "CEnemy.h"
#include "CScenery.h"
#include "CGate.h"

class CEnemy;

class CPlayer {
    private:
        // Imágenes del jugador
        //CImage *img;// ---------------------------------------- Imagenes
        CModel2D* model;
        CScenery* currScenery;
        const Uint8 *keyState;// ------------------------------ Estado del teclado
        SDL_Joystick*   joy;// ................................ Mando que controla el juego
        int x, y;// ------------------------------------------- Posición
        int xMax, yMax, xMin, yMin, xScn, yScn;//.............. Posición máxima, mínima y posición en el escenario
        bool canMove[4], efecto;// ............................ Para comprobar si hay que chequear algún efecto
        direction dir;

        // Parámetros de juego
        int  life;// ........................................... Vida del jugador
        CEnemy *enem[9];// ------------------------------------- Puntero a los enemigos que han causado algún efecto en el jugador
        bool inmortal;// ....................................... Flag de control

        // Funciones de control
        void checkKeyboard();
        void checkJoystick();

        // Funciones de colisión
        void checkColisionUp();
        void checkColisionDown();
        void checkColisionRight();
        void checkColisionLeft();
        void checkEnemies();

        // Movimientos
        void move_Player();// --------- Actualizar posición del jugador
        void moveUp();
        void moveDown();
        void moveRight();
        void moveLeft();

        // Timer
        CTimer *time;

        // Eventos de usuario
        void pushUserEvent(CGate *g);

        // Funciones auxiliares
        std::string getImgFromDir();

    public:
        CPlayer();// ----------- Constructor
        ~CPlayer();// .......... Destructor
        bool Init(int xIni, int yIni, int xRes, int yRes, char *dir, SDL_Renderer *ren, CScenery *scn);// --------- Inicializar jugador
        void update_Player();// ....... Actualizar datos de jugador
        SDL_Texture* get_Tex();
        SDL_Rect* get_Rect();
        SDL_Rect* get_Img_Rect();
        int getXScn();
        int getYScn();
        int getLife();
        void hitPlayer(int i, CEnemy *enem);
        void OnNewScenery(CGate* g, CScenery *scn);
};

#endif
