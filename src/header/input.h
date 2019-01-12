#ifndef _INPUT_H_
#define _INPUT_H_

#include "constantes.h"

//enum { CONTEXT_MENU, CONTEXT_GAME}; // Contexte

typedef struct Input Input;
struct Input {
    SDL_Event m_event;
    SDL_bool m_key[SDL_NUM_SCANCODES];
    SDL_bool m_mouse[8];

    int m_x, m_y;
    int m_xRel, m_yRel;

    //int m_context;
    SDL_bool m_quit;
};

Input new_Input( /*int context*/ ) ;
void updateEvent( Input *this ) ;
void show_mouse( SDL_bool show ) ;
void trap_mouse( SDL_bool trap ) ;

#endif
