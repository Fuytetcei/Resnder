
#include "CApp.h"

Uint32 USER_EVENTS;

// Constructor
CApp::CApp() {
    this->Running = true;
    this->win = NULL;
    this->ren = NULL;
    this->enemy = NULL;
    this->player = NULL;
}

// Función principal
int CApp::OnExecute() {

    // Inicializo
    if(!OnInit()) {
        std::cout<<"Fallo al iniciar.\n";
        return -1;
    }
    std::cout<<"Inicializacion correcta.\n";
    // Para controlar eventos
    SDL_Event Event;

    // Bucle principal
    while(Running) {
        // Miro si hay eventos
        while(SDL_PollEvent(&Event)) {
            OnEvent(&Event);
        }
        // Actualizo datos
        OnLoop();
        // Renderizo en pantalla
        OnRender();
    }
    std::cout<<"Limpio y termino.\n";
    // Limpio memoria
    OnCleanup();
 
    return 0;
}

// Inicialización
bool CApp::OnInit() {

    // Cargo al configuración
    if(!this->OnConfload()){
        std::cout<<"Error al cargar configuración.\n";
        return false;
    }

    // Inicializo la librería SDL
    if(SDL_Init(SDL_INIT_EVERYTHING) < 0) {
        std::cout<<"Error al iniciar SDL.\n";
        return false;
    }

    // Inicializo SDL_image
    // Inicio SDL_image
    int flags = IMG_INIT_PNG | IMG_INIT_TIF | IMG_INIT_JPG;
    int j = IMG_Init(flags);
    if( (j&flags) != flags) {
        std::cout<<"Error al iniciar IMG.\n";
        std::cout<<IMG_GetError()<<std::endl;
        return false;
    }

    // Inicializo SDL_ttf
    if(TTF_Init()==-1) {
        std::cout<<"Error al iniciar TTF.\n";
        std::cout<<TTF_GetError()<<std::endl;
        return false;
    }

    // Registro evento de usuario
    USER_EVENTS = SDL_RegisterEvents(1);
    if(USER_EVENTS == ((Uint32)-1)){
        std::cout<<"Error al registrar evento de usuario.\n";
        return false;
    }

    // Creo la ventana principal
    // win = SDL_CreateWindow("Hello World!", 100, 100, resX, resY, SDL_WINDOW_SHOWN|SDL_WINDOW_FULLSCREEN);
    win = SDL_CreateWindow("RESNDER", 100, 100, resX, resY, SDL_WINDOW_SHOWN);
    if(win == NULL) {
        std::cout<<"Error al crear ventana.\n";
        return false;
    }

    // Creo el renderer
    ren = SDL_CreateRenderer(win, -1, SDL_RENDERER_ACCELERATED|SDL_RENDERER_PRESENTVSYNC);
    if(ren == NULL) {
        std::cout<<"Error al crear renderer.\n";
        return false;
    }

    // Inicio el escenario
    this->scenery = new CScenery(ren);
    if(!this->scenery->Init(0, this->iniX, this->iniY)){
        std::cout<<"Error al cargar escenario.\n";
        return false;
    }

    // Inicio al jugador
    this->player = new CPlayer();
    if(!this->player->Init(650, 500, resX, resY, (char *)"descarga.bmp", ren, scenery)){
        std::cout<<"Error al iniciar jugador\n";
        return false;
    }

    return true;
}

// Actualización de datos
void CApp::OnLoop() {
    //this->enemy->updateEnemy();
    this->player->update_Player();
}

// Renderizado
void CApp::OnRender() {
    // Limpio el render
    SDL_RenderClear(this->ren);
    // Dibujo el fondo
    SDL_RenderCopy(this->ren, this->scenery->get_Tex(), NULL, this->scenery->get_Rect());
    // Dibujo al jugador
    SDL_RenderCopy(this->ren, this->player->get_Tex(), this->player->get_Img_Rect(), this->player->get_Rect());

    // Dibujo el enemigo
    //SDL_RenderCopy(this->ren, this->enemy->get_Image()->get_Tex(), NULL, this->enemy->get_Image()->get_Rect());
    // Refresco la ventana
    SDL_RenderPresent(ren);
}

// Limpiado de datos
void CApp::OnCleanup() {
    delete this->player;
    delete this->scenery;
    // delete img;
    SDL_DestroyRenderer(this->ren);
    SDL_DestroyWindow(this->win);
    SDL_Quit();
}

// Cargo la configuración
bool CApp::OnConfload(){
    char chin[10];

    // Miro si está el archivo de configuración
    std::ifstream fin("conf.ini");
    if(!fin.is_open())
        return false;

    // Cargo la resolución
    fin.getline(chin, 10);
    this->resX = atoi(chin);
    fin.getline(chin, 10);
    this->resY = atoi(chin);
    fin.getline(chin, 10);
    this->iniX = atoi(chin);
    fin.getline(chin, 10);
    this->iniY = atoi(chin);
    return true;
}

// Main
int main(int argc, char* argv[]) {
    CApp theApp;

    // Inicio el juego
    return theApp.OnExecute();
}