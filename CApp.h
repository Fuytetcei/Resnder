#ifndef _CAPP_H_
    #define _CAPP_H_

#include "CBasics.h"
#include "CKeys.h"
#include "CPlayer.h"
#include "CEnemy.h"
#include "CEvent.h"

class CApp : public CEvent {

    private:
        // Datos generales
        bool Running;//---------------------------- Flag de terminación general
        SDL_Window*  win;// ....................... Ventana principal
        SDL_Renderer*   ren;// -------------------- Renderer principal
        int resX, resY;// ......................... Resolución de pantalla
        int iniX, iniY;//,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,
        void drawScenery();

        // Datos del juego
        CImage *img;
        CPlayer *player;
        CEnemy *enemy;
        // CScroll *scenery;
        CScenery* scenery;

        // Funciones internas
        void OnLoadScenery(CGate *gate);// -------------------------- Para cambiar de escenario

    public:
        CApp();// --------------------------- Constructor
        int OnExecute();// .................. Programa principal
        bool OnInit();// -------------------- Inicialización
        void OnEvent(SDL_Event* Event);// ... Gestión de eventos
        void OnLoop();// -------------------- Actualizar datos
        void OnRender();// .................. Renderizar
        void OnCleanup();// ----------------- Limpiar memoria
        bool OnConfload();// .................. Carga la configuración elegida del conf.ini

        // Eventos
        void OnExit();// Para salir
        void OnKeyDown(SDL_Keycode sym, SDL_Scancode mod, Uint16 unicode);
        //void OnKeyUp(SDL_Keycode sym, SDL_Scancode mod, Uint16 unicode);
        void OnLButtonDown(int mX, int mY);
        void OnLButtonUp(int mX, int mY);
        void OnRButtonDown(int mX, int mY);
        void OnRButtonUp(int mX, int mY);
        void OnMButtonDown(int mX, int mY);
        void OnMButtonUp(int mX, int mY);
        void OnMouseWheel(bool Up, bool Down);
        //void OnUser(Uint8 type, int code, void* data1, void* data2);
        //void On_FINGERDOWN();
        //void On_FINGERUP();
        //void On_FINGERMOTION();
        //void On_TEXTEDITING();
        //void On_TEXTINPUT();
        void OnJoyButtonDown(Uint8 which, Uint8 button);
        void OnJoyButtonUp(Uint8 which, Uint8 button);
        //void OnJoyAxis(Uint8 which, Uint8 axis, Sint16 value);// Joystick derecho
        //void OnJoyHat(Uint8 which, Uint8 hat, Uint8 value); // Cruceta
        //void OnUser(Uint8 type, int code, void* data1, void* data2);
        void OnUserEvent(SDL_Event *e);
};

#endif