#include "header/menu.h"
#include "header/fonction_SDL.h"

int loop_menu( SDL_Renderer *renderer, Input *input ) {
    SDL_Color c1 = { 255, 0, 0, 255};
    SDL_Color c2 = { 0, 0, 255, 255};
    int c = 1, int statut = EXIT_FAILURE;
    input.m_quit = SDL_FALSE;
    while(!input.m_quit) {
        updateEvent(&input);
        if(input.m_key[SDL_SCANCODE_ESCAPE] == SDL_TRUE) {
            input.m_quit = SDL_TRUE;
        }

        if(c ==1) {
            setWindowColor(renderer, c1);
            c = 2;
        }
        else {
            setWindowColor(renderer, c2);
            c = 1;
        }

        SDL_RenderPresent(renderer);
        SDL_Delay(20);
    }

    goto Quit;

    statut = EXIT_SUCCESS;

Quit:


    return statut;
}