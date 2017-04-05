
#include "CEvent.h"
 
CEvent::CEvent() {
}
 
CEvent::~CEvent() {
    //Do nothing
}
 
void CEvent::OnEvent(SDL_Event* Event) {
    switch(Event->type) {
        // ----------------------------------------------------------------------------
        // El SO está cerrando la aplicación
        /*case SDL_APP_TERMINATING:{
            On_APP_TERMINATING();
            break;
        }
        // El SO informa de que hay poca memoria
        case SDL_APP_LOWMEMORY:{
            On_APP_LOWMEMORY();
            break;
        }
        // La aplicación está pasando al background
        case SDL_APP_WILLENTERBACKGROUND:{
            On_APP_WILLENTERBACKGROUND();
            break;
        }
        // La aplicación ha pasado al background
        case SDL_APP_DIDENTERBACKGROUND:{
            On_APP_DIDENTERBACKGROUND();
            break;
        }
        // La aplicación está pasando al foreground
        case SDL_APP_WILLENTERFOREGROUND:{
            On_APP_WILLENTERFOREGROUND();
            break;
        }
        // La aplicación ha pasado al foreground
        case SDL_APP_DIDENTERFOREGROUND:{
            On_APP_DIDENTERFOREGROUND();
            break;
        }
        // Ha cambiado el estado de la ventana
        case SDL_WINDOWEVENT:{
            On_WINDOWEVENT();
            break;
        }
        // 
        case SDL_TEXTEDITING:{
            //On_TEXTEDITING();
            break;
        }
        // Introducción de texto
        case SDL_TEXTINPUT:{
            //On_TEXTINPUT();
            break;
        }/*
        // Ha cambiado el idioma del teclado, puede que ya no se correspondan las teclas
        case SDL_KEYMAPCHANGED:{
            On_KEYMAPCHANGED();
            break;
        }
        case SDL_CONTROLLERAXISMOTION:{
            On_CONTROLLERAXISMOTION();
            break;
        }
        case SDL_CONTROLLERBUTTONDOWN:{
            On_CONTROLLERBUTTONDOWN();
            break;
        }
        case SDL_CONTROLLERBUTTONUP:{
            On_CONTROLLERBUTTONUP();
            break;
        }
        case SDL_CONTROLLERDEVICEADDED:{
            On_CONTROLLERDEVICEADDED();
            break;
        }
        case SDL_CONTROLLERDEVICEREMOVED:{
            On_CONTROLLERDEVICEREMOVED();
            break;
        }
        case SDL_CONTROLLERDEVICEREMAPPED:{
            On_CONTROLLERDEVICEREMAPPED();
            break;
        }
        // Se ha tocado el touchpad
        case SDL_FINGERDOWN:{
            On_FINGERDOWN();
            break;
        }
        // Se ha dejado de tocar el touchpad
        case SDL_FINGERUP:{
            On_FINGERUP();
            break;
        }
        // Se mueve el dedo por el touchpad
        case SDL_FINGERMOTION:{
            On_FINGERMOTION();
            break;
        }*/
        // ----------------------------------------------------------------------------
        // Se ha pulsado una tecla
        case SDL_KEYDOWN: {
            OnKeyDown(Event->key.keysym.sym, Event->key.keysym.scancode, Event->key.keysym.mod);
            break;
        }
        // Se ha dejado de pulsar la tecla
        case SDL_KEYUP: {
            //OnKeyUp(Event->key.keysym.sym, Event->key.keysym.scancode, Event->key.keysym.mod);
            break;
        }
        // Se ha mpvido el ratón
        /*case SDL_MOUSEMOTION: {
            OnMouseMove(Event->motion.x,Event->motion.y,Event->motion.xrel,Event->motion.yrel,(Event->motion.state&SDL_BUTTON(SDL_BUTTON_LEFT))!=0,(Event->motion.state&SDL_BUTTON(SDL_BUTTON_RIGHT))!=0,(Event->motion.state&SDL_BUTTON(SDL_BUTTON_MIDDLE))!=0);
            break;
        }
        // Se ha pulsado un botón del ratón
        case SDL_MOUSEBUTTONDOWN: {
            switch(Event->button.button) {
                case SDL_BUTTON_LEFT: {
                    OnLButtonDown(Event->button.x,Event->button.y);
                    break;
                }
                case SDL_BUTTON_RIGHT: {
                    OnRButtonDown(Event->button.x,Event->button.y);
                    break;
                }
                case SDL_BUTTON_MIDDLE: {
                    OnMButtonDown(Event->button.x,Event->button.y);
                    break;
                }
            }
            break;
        }
        // Se ha dejado de pulsar el botón del ratón
        case SDL_MOUSEBUTTONUP:    {
            switch(Event->button.button) {
                case SDL_BUTTON_LEFT: {
                    OnLButtonUp(Event->button.x,Event->button.y);
                    break;
                }
                case SDL_BUTTON_RIGHT: {
                    OnRButtonUp(Event->button.x,Event->button.y);
                    break;
                }
                case SDL_BUTTON_MIDDLE: {
                    OnMButtonUp(Event->button.x,Event->button.y);
                    break;
                }
            }
            break;
        }
        // Se ha movido la rueda del ratón
        case SDL_MOUSEWHEEL:{
            OnMouseWheel(true, false);
            break;
        }
        // Se ha movido un eje del joystick
        case SDL_JOYAXISMOTION: {
            OnJoyAxis(Event->jaxis.which,Event->jaxis.axis,Event->jaxis.value);
            break;
            }
        // Se ha movido la bola del joystick
        case SDL_JOYBALLMOTION: {
            OnJoyBall(Event->jball.which,Event->jball.ball,Event->jball.xrel,Event->jball.yrel);
            break;
        }
        // Se ha movido el hat del joystick
        case SDL_JOYHATMOTION: {
            OnJoyHat(Event->jhat.which,Event->jhat.hat,Event->jhat.value);
            break;
        }
        // Se ha pulsado un botón del joystick
        case SDL_JOYBUTTONDOWN: {
            OnJoyButtonDown(Event->jbutton.which,Event->jbutton.button);
            break;
        }
        // Se ha dejado de pulsar un botón
        case SDL_JOYBUTTONUP: {
            OnJoyButtonUp(Event->jbutton.which,Event->jbutton.button);
            break;
        }
        // Se ha conectado un joystick
        case SDL_JOYDEVICEADDED:{
            On_JOYDEVICEADDED();
            break;
        }
        // Se ha desconectado el joystick
        case SDL_JOYDEVICEREMOVED:{
            On_JOYDEVICEREMOVED();
            break;
        }*/
        // El usuario quiere cerrar la aplicación
        case SDL_QUIT: {
            OnExit();
            break;
        }
        // Evento del SO
        /*case SDL_SYSWMEVENT:{
            //Ignore
            break;
        }*/
 
        /*case SDL_VIDEORESIZE: {
            OnResize(Event->resize.w,Event->resize.h);
            break;
        }
 
        case SDL_VIDEOEXPOSE: {
            OnExpose();
            break;
        }*/
        case SDL_USEREVENT:{
            SDL_FlushEvent(SDL_USEREVENT);
            OnUserEvent(Event);
        }
        // El resto de eventos
        default: {
            //OnUser(Event->user.type,Event->user.code,Event->user.data1,Event->user.data2);
            break;
        }
    }
}
 
void CEvent::OnInputFocus() {

}
void CEvent::OnInputBlur() {

}
void CEvent::OnKeyDown(SDL_Keycode sym, SDL_Scancode mod, Uint16 unicode) {

}
void CEvent::OnKeyUp(SDL_Keycode sym, SDL_Scancode mod, Uint16 unicode) {

}
void CEvent::OnMouseFocus() {

}
void CEvent::OnMouseBlur() {

}
void CEvent::OnMouseMove(int mX, int mY, int relX, int relY, bool Left,bool Right,bool Middle) {

}
void CEvent::OnMouseWheel(bool Up, bool Down) {

}
void CEvent::OnLButtonDown(int mX, int mY) {

}
void CEvent::OnLButtonUp(int mX, int mY) {

}
void CEvent::OnRButtonDown(int mX, int mY) {

}
void CEvent::OnRButtonUp(int mX, int mY) {

}
void CEvent::OnMButtonDown(int mX, int mY) {

}
void CEvent::OnMButtonUp(int mX, int mY) {

}
void CEvent::OnJoyAxis(Uint8 which,Uint8 axis,Sint16 value) {

}
void CEvent::OnJoyButtonDown(Uint8 which,Uint8 button) {

}
void CEvent::OnJoyButtonUp(Uint8 which,Uint8 button) {

}
void CEvent::OnJoyHat(Uint8 which,Uint8 hat,Uint8 value) {

}
void CEvent::OnJoyBall(Uint8 which,Uint8 ball,Sint16 xrel,Sint16 yrel) {

}
void CEvent::OnMinimize() {

}
void CEvent::OnRestore() {

}
void CEvent::OnResize(int w,int h) {

}
void CEvent::OnExpose() {

}
void CEvent::OnUser(Uint8 type, int code, void* data1, void* data2) {

}
void CEvent::OnExit() {
    //Pure virtual, do nothing
}
void CEvent::On_APP_TERMINATING(){

}
void CEvent::On_APP_LOWMEMORY(){

}
void CEvent::On_APP_WILLENTERBACKGROUND(){

}
void CEvent::On_APP_DIDENTERBACKGROUND(){

}
void CEvent::On_APP_WILLENTERFOREGROUND(){

}
void CEvent::On_APP_DIDENTERFOREGROUND(){

}
void CEvent::On_WINDOWEVENT(){

}
void CEvent::On_SYSWMEVENT(){

}
void CEvent::On_TEXTEDITING(){

}
void CEvent::On_TEXTINPUT(){

}
void CEvent::On_KEYMAPCHANGED(){

}
void CEvent::On_CONTROLLERAXISMOTION(){

}
void CEvent::On_CONTROLLERBUTTONDOWN(){

}
void CEvent::On_CONTROLLERBUTTONUP(){

}
void CEvent::On_CONTROLLERDEVICEADDED(){

}
void CEvent::On_CONTROLLERDEVICEREMOVED(){

}
void CEvent::On_CONTROLLERDEVICEREMAPPED(){

}
void CEvent::On_FINGERDOWN(){

}
void CEvent::On_FINGERUP(){

}
void CEvent::On_FINGERMOTION(){

}
void CEvent::On_JOYDEVICEADDED(){

}
void CEvent::On_JOYDEVICEREMOVED(){
}
void CEvent::OnUserEvent(SDL_Event *e){
}