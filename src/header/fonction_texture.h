#ifndef _FONCTION_TEXTURE_H_
#define _FONCTION_TEXTURE_H_

#include "constantes.h"

typedef struct Texture Texture;
struct Texture {
    SDL_Renderer *m_renderer;
    SDL_Texture *m_texture;
    SDL_Rect m_rect;
};

//construire
Texture new_Texture( SDL_Renderer *renderer ) ;

//fromImg
//void fonction_fromImage();

//fromTxt
void fonction_fromTxt( Texture *this, TTF_Font *font, const char *txt, SDL_Color color ) ;
void fonction_print( Texture this ) ;

//centrer

#endif

//gerer la destruction