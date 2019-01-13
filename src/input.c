#include "header/input.h"

//Constructeur : cree / initialise / renvoie une insance
Input new_Input() {
    Input tmp;
    tmp.m_x = 0;
    tmp.m_y = 0;
    tmp.m_xRel = 0;
    tmp.m_yRel = 0;
    tmp.m_quit = SDL_FALSE;

    for(int i = 0 ; i < SDL_NUM_SCANCODES ; i++) {
        tmp.m_key[i] = SDL_FALSE;
    }

    for(int i = 0 ; i < 8 ; i++) {
        tmp.m_mouse[i] = SDL_FALSE;
    }

    tmp.updateEvent = function_updateEvent;

    return tmp;
}

//Gere les evenement
void function_updateEvent( Input *this ) {
    //Mouse move init 
    this->m_xRel = 0;
    this->m_yRel = 0;

    while(SDL_PollEvent(&this->m_event)) {
        switch(this->m_event.type) {
            //Keyboard
            case SDL_KEYDOWN:
                this->m_key[this->m_event.key.keysym.scancode] = SDL_TRUE;
                break;
            case SDL_KEYUP:
                this->m_key[this->m_event.key.keysym.scancode] = SDL_FALSE;
                break;
            //Mouse button
            case SDL_MOUSEBUTTONDOWN:
                this->m_mouse[this->m_event.button.button] = SDL_TRUE;
                break;
            case SDL_MOUSEBUTTONUP:
                this->m_mouse[this->m_event.button.button] = SDL_FALSE;
                break;
            //Mouse move
            case SDL_MOUSEMOTION:
                this->m_x = this->m_event.motion.x;
                this->m_y = this->m_event.motion.y;
                this->m_xRel = this->m_event.motion.xrel;
                this->m_yRel = this->m_event.motion.yrel;
                break;
            //Window event
            case SDL_WINDOWEVENT:
                if(this->m_event.window.event == SDL_WINDOWEVENT_CLOSE) this->m_quit = SDL_TRUE;
                break;
            default:
                break;
        }
    }
}

//Masquer ou non le curseure de la sourie
void show_mouse( SDL_bool show ) {
    if(show) {
        if(SDL_ShowCursor(SDL_ENABLE) < 0) {
            fprintf(stderr, "Erreur enabling SDL_ShowCursor : %s\n", SDL_GetError());
        }
    }
    else {
        if(SDL_ShowCursor(SDL_DISABLE) < 0) {
            fprintf(stderr, "Erreur disabling SDL_ShowCursor : %s\n", SDL_GetError());
        }
    }
}

//Piege la sourie dans l'écran
void trap_mouse( SDL_bool trap ) {
    if(trap) {
        if(SDL_SetRelativeMouseMode(SDL_TRUE) != 0) {
            fprintf(stderr, "Erreur enabling SDL_SetRelativeMouseMode : %s\n", SDL_GetError());
        }
    }
    else {
        if(SDL_SetRelativeMouseMode(SDL_FALSE) != 0) {
            fprintf(stderr, "Erreur disabling SDL_SetRelativeMouseMode : %s\n", SDL_GetError());
        }
    }
}

//get_key

//get_mouse_button

//get_mouse_move

//get_mouse_position

//get_mouse_relPosition

//take_mouse_focus