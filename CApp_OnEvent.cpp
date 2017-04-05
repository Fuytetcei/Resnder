
#include "CApp.h"

void CApp::OnExit() {
    std::cout<<"Saliendo.\n";
    Running = false;
}
// Gestión de eventos
void CApp::OnEvent(SDL_Event* Event) {
    CEvent::OnEvent(Event);
}
/*
void CApp::OnInputFocus() {
    std::cout<<"OnInputFocus\n";
}

void CApp::OnInputBlur() {
    std::cout<<"OnInputBlur\n";
}
*/
// Tecla pulsada
void CApp::OnKeyDown(SDL_Keycode sym, SDL_Scancode mod, Uint16 unicode) {

    if(sym == SDLK_ESCAPE)
        this->Running = false;

}/*
// La tecla ya no se pulsa
void CApp::OnKeyUp(SDL_Keycode sym, SDL_Scancode mod, Uint16 unicode) {
    //this->player->move_Player(SDL_GetKeyboardState(NULL));
    std::cout<<"OnKeyUp\n";
}

void CApp::OnMouseFocus() {
    std::cout<<"OnMouseFocus\n";
}

void CApp::OnMouseBlur() {
    std::cout<<"OnMouseBlur\n";
}

void CApp::OnMouseMove(int mX, int mY, int relX, int relY, bool Left,bool Right,bool Middle) {
    std::cout<<"OnMouseMove\n";
}
*/
void CApp::OnMouseWheel(bool Up, bool Down) {

}

void CApp::OnLButtonDown(int mX, int mY) {

}
void CApp::OnLButtonUp(int mX, int mY) {

}

void CApp::OnRButtonDown(int mX, int mY) {

}

void CApp::OnRButtonUp(int mX, int mY) {

}

void CApp::OnMButtonDown(int mX, int mY) {

}

void CApp::OnMButtonUp(int mX, int mY) {

}
/*
void CApp::OnJoyAxis(Uint8 which,Uint8 axis,Sint16 value) {
    std::cout<<"OnJoyAxis\n";
}*/
void CApp::OnJoyButtonDown(Uint8 which,Uint8 button) {

}

void CApp::OnJoyButtonUp(Uint8 which,Uint8 button) {

}
/*
void CApp::OnJoyHat(Uint8 which, Uint8 hat, Uint8 value) {
    std::cout<<"OnJoyHat\n";
}

void CApp::OnJoyBall(Uint8 which,Uint8 ball,Sint16 xrel,Sint16 yrel) {
    std::cout<<"OnJoyBall\n";
}

void CApp::OnMinimize() {
    std::cout<<"OnMinimize\n";
}

void CApp::OnRestore() {
    std::cout<<"OnRestore\n";
}

void CApp::OnResize(int w,int h) {
    std::cout<<"OnResize\n";
}

void CApp::OnExpose() {
    std::cout<<"OnExpose\n";
}

void CApp::OnUser(Uint8 type, int code, void* data1, void* data2) {
    std::cout<<"OnUser\n";
}

void CApp::On_APP_TERMINATING(){
    std::cout<<"On_APP_TERMINATING\n";
}
void CApp::On_APP_LOWMEMORY(){
    std::cout<<"On_APP_LOWMEMORY\n";
}
void CApp::On_APP_WILLENTERBACKGROUND(){
    std::cout<<"On_APP_WILLENTERBACKGROUND\n";
}
void CApp::On_APP_DIDENTERBACKGROUND(){
    std::cout<<"On_APP_DIDENTERBACKGROUND\n";
}
void CApp::On_APP_WILLENTERFOREGROUND(){
    std::cout<<"On_APP_WILLENTERFOREGROUND\n";
}
void CApp::On_APP_DIDENTERFOREGROUND(){
    std::cout<<"On_APP_DIDENTERFOREGROUND\n";
}
void CApp::On_WINDOWEVENT(){
    std::cout<<"On_WINDOWEVENT\n";
}
void CApp::On_SYSWMEVENT(){
    std::cout<<"On_SYSWMEVENT\n";
}
void CApp::On_TEXTEDITING(){
    //this->player->move_Player(SDL_GetKeyboardState(NULL));
    std::cout<<"On_TEXTEDITING\n";
}
// Para combinaciones de teclas
void CApp::On_TEXTINPUT(){
    //this->player->move_Player(SDL_GetKeyboardState(NULL));
    std::cout<<"On_TEXTINPUT\n";
}
void CApp::On_KEYMAPCHANGED(){
    std::cout<<"On_KEYMAPCHANGED\n";
}
void CApp::On_CONTROLLERAXISMOTION(){
    std::cout<<"On_CONTROLLERAXISMOTION\n";
}
void CApp::On_CONTROLLERBUTTONDOWN(){
    std::cout<<"On_CONTROLLERBUTTONDOWN\n";
}
void CApp::On_CONTROLLERBUTTONUP(){
    std::cout<<"On_CONTROLLERBUTTONUP\n";
}
void CApp::On_CONTROLLERDEVICEADDED(){
    std::cout<<"On_CONTROLLERDEVICEADDED\n";
}
void CApp::On_CONTROLLERDEVICEREMOVED(){
    std::cout<<"On_CONTROLLERDEVICEREMOVED\n";
}
void CApp::On_CONTROLLERDEVICEREMAPPED(){
    std::cout<<"On_CONTROLLERDEVICEREMAPPED\n";
}
void CApp::On_FINGERDOWN(){
    std::cout<<"On_FINGERDOWN\n";
}
void CApp::On_FINGERUP(){
    std::cout<<"On_FINGERUP\n";
}
void CApp::On_FINGERMOTION(){
    std::cout<<"On_FINGERMOTION\n";
}

void CApp::On_JOYDEVICEADDED(){
    std::cout<<"On_JOYDEVICEADDED\n";
}
void CApp::On_JOYDEVICEREMOVED(){
    std::cout<<"On_JOYDEVICEREMOVED\n";
}*/
void CApp::OnUserEvent(SDL_Event *e){
    switch(e->user.code){
        case SCENERYCHANGE:
            OnLoadScenery((CGate*)e->user.data1);
            break;
        default:
            std::cout<<"No se reconoce el código.\n";
    }
}

void CApp::OnLoadScenery(CGate *gate){
    CScenery *nuevo = NULL;
    CGate* aux1=NULL;
    SDL_Rect *r=NULL;
    int newX, newY;
    const unsigned char *aux3=NULL;

    // Guardo el estado del escenario (FUTURO)

    // Inicio el escenario
    nuevo = new CScenery(this->ren);
    if(!nuevo->Init(gate->getDir(), 0, 0)){
        std::cout<<"Error al cargar el nuevo escenario.\n";
        exit(-1);
    }

    // Busco la puerta correspondiente
    aux1 = nuevo->getGate(gate->getCode());

    r = aux1->getRect();
    // Inicio el nuevo escenario donde corresponda
    switch(aux1->getOrientation()){
        case UP:
            newX = (this->resX/2)-r->x;
            newY = (this->resY/2)-r->y;
            break;
        case DOWN:
            newX = (this->resX/2)-r->x;
            newY = (this->resY/4)-r->y-r->h;
            break;
        case RIGHT:
            newX = (this->resX/4)-r->x-r->w;
            newY = (this->resY/2)-r->y;
            break;
        case LEFT:
            newX = ((this->resX*3)/4)-r->x;
            newY = (this->resY/2)-r->y;
            break;
        default:
            break;
    }

    nuevo->setPos(newX, newY);
    // Sitúo al jugador a la salida de la puerta
    this->player->OnNewScenery(aux1, nuevo);

    // Destruyo el antiguo escenario y el auxiliar
    delete this->scenery;

    // Guardo el nuevo escenario
    this->scenery = nuevo;
}