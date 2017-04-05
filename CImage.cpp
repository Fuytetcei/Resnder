
#include "CImage.h"

// Constructor
CImage::CImage(SDL_Renderer *ren) {
    this->ren = ren;
    this->tex = NULL;
    this->rect = NULL;
    this->img = NULL;
}

CImage::~CImage(){
    delete this->rect;
    SDL_DestroyTexture(tex);
    SDL_FreeSurface(img);
}

bool CImage::Init(std::string dir, int xIni, int yIni){

    // Cargo la imagen
    this->img = IMG_Load(dir.c_str());
    if(!this->img){
        std::cout<<"Error al cargar imagen en CImage.\n";
        return false;
    }
    // Creo la textura
    this->tex = SDL_CreateTextureFromSurface(ren, img);
    if(this->tex == NULL) {
        std::cout<<"Textura no creada.\n";
        return false;
    }
    // Creo el rectángulo para dibujar
    this->rect = new SDL_Rect();
    this->rect->x = xIni;// Por defecto dibujo en (0,0))
    this->rect->y = yIni;
    this->rect->h = this->img->h;
    this->rect->w = this->img->w;

    return true;
}

SDL_Rect* CImage::get_Rect(){
    return this->rect;
}
SDL_Texture* CImage::get_Tex(){
    return this->tex;
}

// Obtener anchura o altura de la imagen
int CImage::get_width(){
    return this->img->w;
}
int CImage::get_height(){
    return this->img->h;
}

void CImage::addXpos() {
    this->rect->x++;
}
void CImage::substractXpos() {
    this->rect->x--;
}
void CImage::addYpos() {
    this->rect->y++;
}
void CImage::substractYpos() {
    this->rect->y--;
}

void CImage::setHeight(int h){
    this->rect->h = h;
}

void CImage::setWidth(int w){
    this->rect->w = w;
}