
#include "CModel2D.h"

// Constructor y destructor
CModel2D::CModel2D(){
    this->animations = NULL;
    this->current = NULL;
    this->num = 0;
}
CModel2D::~CModel2D(){
    // Libero la memoria
    for(int i=0;i<9;i++)
        free(this->animations[i]);
    free(this->animations);
}

// Función de inicialización
bool CModel2D::Init(direction dir, SDL_Renderer* ren){
    int i;
    std::string dirs[9];

    // Reservo memoria para los punteros
    this->animations = (CImage**)malloc(sizeof(CImage*)*9);
    if(this->animations == NULL){
        std::cout<<"Error al crear CImage.\n";
        return false;
    }
    // Reservo memoria para las animaciones (de momento solo una imagen))
    /*for(i=0;i<8;i++)
        this->animations[i] = (CImage*)malloc(sizeof(CImage));*/
    // Cargo las imágenes, OJO!!, en el futuro habrá que concatenar con la dirección del modelo correspondiente
    // Ej: dirs[DIR_UP] = dir+"arriba.png";
    dirs[DIR_UP] = "arriba.png";
    dirs[DIR_DOWN] = "abajo.png";
    dirs[DIR_LEFT] = "izquierda.png";
    dirs[DIR_RIGHT] = "derecha.png";
    dirs[DIR_UP_LEFT] = "arriba-izquierda.png";
    dirs[DIR_UP_RIGHT] = "arriba-derecha.png";
    dirs[DIR_DOWN_LEFT] = "abajo-izquierda.png";
    dirs[DIR_DOWN_RIGHT] = "abajo-derecha.png";
    dirs[DIR_STATIC] = "static.png";
    for(i=0;i<9;i++){
        dirs[i] = "obj/Player/animacioTest/" + dirs[i];
        this->animations[i] = new CImage(ren);
        if(!this->animations[i]->Init(dirs[i], 0, 0)){
            std::cout<<"Error al crear CImage: "<<dirs[i]<<"\n";
            return false;
        }
        // Reduzco el tamaño de la imagen
        this->animations[i]->setHeight(32);
        this->animations[i]->setWidth(32);
    }

    // Escojo la dirección por defecto
    this->current = this->animations[dir];

    // Cojo el primer frame
    this->curr.x = 0;
    this->curr.y = 0;
    this->curr.h = 32;
    this->curr.w = 32;

    return true;
}
// Cambia la a la animación indicada
void CModel2D::OnDirectionChange(direction dir){
    this->current = this->animations[dir];
}
// Devuelve la imagen correspondiente y su rectángulo
CImage* CModel2D::getCurrent(){
    return this->current;
}
SDL_Rect* CModel2D::getCurrentRect(){
    return &(this->curr);
}

// Ojo a esto!!, habrá que guardar las dimensiones de cada modelo para poder trabajar con diferentes tamaños
int CModel2D::getHeight(){
    return 32;
}
int CModel2D::getWidth(){
    return 32;
}

// Calculo el siguiente frame
void CModel2D::next(){
    this->num = (this->num + 1) % 24;
    switch(num){
        case 0:
            this->curr.x = 0;
            this->curr.y = 0;
            break;
        case 1:
            this->curr.x = 32;
            this->curr.y = 0;
            break;
        case 2:
            this->curr.x = 64;
            this->curr.y = 0;
            break;
        case 3:
            this->curr.x = 96;
            this->curr.y = 0;
            break;
        case 4:
            this->curr.x = 128;
            this->curr.y = 0;
            break;
        case 5:
            this->curr.x = 0;
            this->curr.y = 32;
            break;
        case 6:
            this->curr.x = 32;
            this->curr.y = 32;
            break;
        case 7:
            this->curr.x = 64;
            this->curr.y = 32;
            break;
        case 8:
            this->curr.x = 96;
            this->curr.y = 32;
            break;
        case 9:
            this->curr.x = 128;
            this->curr.y = 32;
            break;
        case 10:
            this->curr.x = 0;
            this->curr.y = 64;
            break;
        case 11:
            this->curr.x = 32;
            this->curr.y = 64;
            break;
        case 12:
            this->curr.x = 64;
            this->curr.y = 64;
            break;
        case 13:
            this->curr.x = 96;
            this->curr.y = 64;
            break;
        case 14:
            this->curr.x = 128;
            this->curr.y = 64;
            break;
        case 15:
            this->curr.x = 0;
            this->curr.y = 96;
            break;
        case 16:
            this->curr.x = 32;
            this->curr.y = 96;
            break;
        case 17:
            this->curr.x = 64;
            this->curr.y = 96;
            break;
        case 18:
            this->curr.x = 96;
            this->curr.y = 96;
            break;
        case 19:
            this->curr.x = 128;
            this->curr.y = 96;
            break;
        case 20:
            this->curr.x = 0;
            this->curr.y = 128;
            break;
        case 21:
            this->curr.x = 32;
            this->curr.y = 128;
            break;
        case 22:
            this->curr.x = 64;
            this->curr.y = 128;
            break;
        case 23:
            this->curr.x = 96;
            this->curr.y = 128;
            break;
        default:
            break;     
    }
}