#include "header/constantes.h"
#include "header/fonction_SDL.h"
#include "header/input.h"
#include "header/menu.h"


int main( int argc, char **argv ) {
    (void)argc;
    (void)argv;
    Input input = new_Input();
    int statut = EXIT_FAILURE;
    SDL_Window *window = NULL;
    SDL_Renderer *renderer = NULL;
    //SDL_Texture *texture = NULL;
    SDL_Color gray = { 171, 171, 171, 255};

    if(init_SDL( &window, &renderer, SDL_INIT_VIDEO, SDL_WINDOW_RESIZABLE | SDL_WINDOW_SHOWN ) != 0) {
        fprintf(stdout,"Échec de init_SDL (%s)\n",SDL_GetError());
        goto Quit;
    }

    while(!input.m_quit) {
        input.updateEvent(&input);
        if(input.m_key[SDL_SCANCODE_ESCAPE] == SDL_TRUE) {
            input.m_quit = SDL_TRUE;
        }
        setWindowColor(renderer, gray);
        SDL_RenderPresent(renderer);
        SDL_Delay(200);

        loop_menu(renderer, &input);

        setWindowColor(renderer, gray);
        SDL_RenderPresent(renderer);
        SDL_Delay(200);
    }
    

    statut = EXIT_SUCCESS;

Quit:
    //if( texture != NULL) SDL_DestroyTexture(texture);
    if(renderer != NULL) SDL_DestroyRenderer(renderer);
    if(window != NULL) SDL_DestroyWindow(window);
    TTF_Quit();
    SDL_Quit();

    return statut;
}
