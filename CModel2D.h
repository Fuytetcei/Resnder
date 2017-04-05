
#ifndef CMODEL2D_H
#define CMODEL2D_H

#include "CModel.h"

class CModel2D : CModel {
    private:
        int num;                // 
        CImage* current;        // Frame actual
        CImage** animations;    // Colección de frames
        SDL_Rect curr;          // Rectángulo del frame actual
        direction currDir;      // Dirección a la que apunta el modelo
    public:
        CModel2D();
        ~CModel2D();
        CImage* getCurrent();
        SDL_Rect* getCurrentRect();
        bool Init(direction dir, SDL_Renderer* ren);
        void OnDirectionChange(direction dir);
        void next();
        int getHeight();
        int getWidth();
};

#endif