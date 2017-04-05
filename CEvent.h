
#ifndef _CEVENT_H
#define _CEVENT_H

#include "CBasics.h"

class CEvent{
    private:
    public:
        CEvent();

        virtual ~CEvent();
        virtual void OnEvent(SDL_Event* Event);
        virtual void OnInputFocus();
        virtual void OnInputBlur();
        virtual void OnKeyDown(SDL_Keycode sym, SDL_Scancode mod, Uint16 unicode);
        virtual void OnKeyUp(SDL_Keycode sym, SDL_Scancode mod, Uint16 unicode);
        virtual void OnMouseFocus();
        virtual void OnMouseBlur();
        virtual void OnMouseMove(int mX, int mY, int relX, int relY, bool Left,bool Right,bool Middle);
        virtual void OnMouseWheel(bool Up, bool Down);    //Not implemented
        virtual void OnLButtonDown(int mX, int mY);
        virtual void OnLButtonUp(int mX, int mY);
        virtual void OnRButtonDown(int mX, int mY);
        virtual void OnRButtonUp(int mX, int mY);
        virtual void OnMButtonDown(int mX, int mY);
        virtual void OnMButtonUp(int mX, int mY);
        virtual void OnJoyAxis(Uint8 which, Uint8 axis, Sint16 value);
        virtual void OnJoyButtonDown(Uint8 which, Uint8 button);
        virtual void OnJoyButtonUp(Uint8 which, Uint8 button);
        virtual void OnJoyHat(Uint8 which, Uint8 hat, Uint8 value);
        virtual void OnJoyBall(Uint8 which, Uint8 ball, Sint16 xrel, Sint16 yrel);
        virtual void OnMinimize();
        virtual void OnRestore();
        virtual void OnResize(int w,int h);
        virtual void OnExpose();
        virtual void OnExit();
        virtual void OnUser(Uint8 type, int code, void* data1, void* data2);
        virtual void On_APP_TERMINATING();
        virtual void On_APP_LOWMEMORY();
        virtual void On_APP_WILLENTERBACKGROUND();
        virtual void On_APP_DIDENTERBACKGROUND();
        virtual void On_APP_WILLENTERFOREGROUND();
        virtual void On_APP_DIDENTERFOREGROUND();
        virtual void On_WINDOWEVENT();
        virtual void On_SYSWMEVENT();
        virtual void On_TEXTEDITING();
        // Para combinación de teclas
        virtual void On_TEXTINPUT();
        virtual void On_KEYMAPCHANGED();
        virtual void On_CONTROLLERAXISMOTION();
        virtual void On_CONTROLLERBUTTONDOWN();
        virtual void On_CONTROLLERBUTTONUP();
        virtual void On_CONTROLLERDEVICEADDED();
        virtual void On_CONTROLLERDEVICEREMOVED();
        virtual void On_CONTROLLERDEVICEREMAPPED();
        virtual void On_FINGERDOWN();
        virtual void On_FINGERUP();
        virtual void On_FINGERMOTION();
        virtual void On_JOYDEVICEADDED();
        virtual void On_JOYDEVICEREMOVED();

        // Evento de usuario
        virtual void OnUserEvent(SDL_Event *e);
};

#endif

