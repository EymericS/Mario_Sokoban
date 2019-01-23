#include "header/fonction_SDL.h"

int init_SDL( SDL_Window **window, SDL_Renderer **renderer, Uint32 init_flags, Uint32 create_flags ) {
    int statut = EXIT_FAILURE;

    if(SDL_Init(init_flags) != 0) {
        fprintf(stdout,"Échec de l'initialisation de la SDL (%s)\n",SDL_GetError());
        goto Quit;
    }

    if(TTF_Init() != 0) {
        fprintf(stdout,"Échec de TTF_Init (%s)\n",TTF_GetError());
        goto Quit;
    }

    if(SDL_CreateWindowAndRenderer(WINDOW_WIDTH, WINDOW_HEIGHT, create_flags, window, renderer) != 0) {
        fprintf(stdout,"Échec de SDL_CreateWindowAndRenderer (%s)\n",SDL_GetError());
        goto Quit;
    }

    statut = EXIT_SUCCESS;

 Quit:

    return statut;
}

int setWindowColor(SDL_Renderer *renderer, SDL_Color color) {
    int statut = EXIT_FAILURE;

    if(SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a) < 0) {
        fprintf(stdout,"Échec de SDL_SetRenderDrawColor (%s)\n",SDL_GetError());
        goto Quit;
    }

    if(SDL_RenderClear(renderer) < 0) {
        fprintf(stdout,"Échec de SDL_RenderClear (%s)\n",SDL_GetError());
        goto Quit;
    }

    statut = EXIT_SUCCESS;

 Quit:

    return statut;  
}

int load_Media() {
    int statut = EXIT_FAILURE;

    ARIAL_16 = NULL;
    ARIAL_16 = TTF_OpenFont(ARIAL_TTF_PATH, 16);
    if( ARIAL_16 == NULL ) {
        fprintf(stdout,"Échec de TTF_OpenFont(%s) : %s\n", ARIAL_TTF_PATH,TTF_GetError());
        goto Quit;
    }

    statut = EXIT_SUCCESS;

 Quit:

    return statut;

    //free media
}

SDL_Texture *loadImage(const char path[], SDL_Renderer *renderer)
{
    SDL_Surface *tmp = NULL; 
    SDL_Texture *texture = NULL;
    tmp = SDL_LoadBMP(path);
    if(NULL == tmp)
    {
        fprintf(stderr, "Erreur SDL_LoadBMP : %s", SDL_GetError());
        return NULL;
    }
    texture = SDL_CreateTextureFromSurface(renderer, tmp);
    SDL_FreeSurface(tmp);
    if(NULL == texture)
    {
        fprintf(stderr, "Erreur SDL_CreateTextureFromSurface : %s", SDL_GetError());
        return NULL;
    }
    return texture;
}