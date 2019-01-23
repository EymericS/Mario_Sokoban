#ifndef _FONCTION_SDL_H_
#define _FONCTION_SDL_H_

#include "constantes.h"


int init_SDL( SDL_Window **window, SDL_Renderer **renderer, Uint32 init_flags, Uint32 create_flags ) ;
int setWindowColor(SDL_Renderer *renderer, SDL_Color color) ;
int load_Media() ;

#endif