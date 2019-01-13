#ifndef _INPUT_H_
#define _INPUT_H_

#include "constantes.h"

typedef struct Input Input;
typedef void (*m_updateEvent)( Input * );

struct Input {
    SDL_Event m_event;
    SDL_bool m_key[SDL_NUM_SCANCODES];
    SDL_bool m_mouse[8];

    int m_x, m_y;
    int m_xRel, m_yRel;

    SDL_bool m_quit;

    m_updateEvent updateEvent;

};

Input new_Input() ;

void function_updateEvent( Input *this ) ;
void show_mouse( SDL_bool show ) ;
void trap_mouse( SDL_bool trap ) ;

#endif
