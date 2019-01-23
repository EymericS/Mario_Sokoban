#include "header/constantes.h"
#include "header/fonction_SDL.h"
#include "header/input.h"
#include "header/menu.h"

#include "header/fonction_texture.h"


/* */
const SDL_Color COLOR_GRAY = {171, 171, 171, 255};
const SDL_Color COLOR_RED = { 255, 0, 0, 255};
/* */

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
        fprintf(stdout,"Échec de init_SDL\n");
        goto Quit;
    }

    if(load_Media() != 0) {
        fprintf(stdout,"Échec de load_Media\n");
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
