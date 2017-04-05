#ifndef _CIMAGE_H_
    #define _CIMAGE_H_

#include "CBasics.h"
#include "CData.h"

class CImage {
    protected:
        SDL_Renderer *ren;
        SDL_Texture  *tex;
        SDL_Surface  *img;
        SDL_Rect     *rect;
    public:
        CImage(SDL_Renderer *ren);// ----------------- Constructores
        ~CImage();// ................................. Destructor
        bool Init(std::string dir, int xIni, int yIni);// ---------------------- Inicialización
        SDL_Rect* get_Rect();// ...................... Obtener rectángulo.
        SDL_Texture* get_Tex();// -------------------- Obtener textura
        int get_width();// ........................... Obtener anchura o altura de la imagen
        int get_height();
        void addXpos();
        void addYpos();
        void substractXpos();
        void substractYpos();
        void setHeight(int w);
        void setWidth(int h);
};

#endif