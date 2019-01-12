#include "header/fonction_SDL.h"

int init_SDL( SDL_Window **window, SDL_Renderer **renderer, Uint32 init_flags, Uint32 create_flags ) {
    if(SDL_Init(init_flags) != 0) {
        fprintf(stdout,"Échec de l'initialisation de la SDL (%s)\n",SDL_GetError());
        return -1;
    }
    if(SDL_CreateWindowAndRenderer(WINDOW_WIDTH, WINDOW_HEIGHT, create_flags, window, renderer) != 0) {
        fprintf(stdout,"Échec de SDL_CreateWindowAndRenderer (%s)\n",SDL_GetError());
        return -1;
    }

    return 0;
}

int setWindowColor(SDL_Renderer *renderer, SDL_Color color) {
    if(SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a) < 0) {
        fprintf(stdout,"Échec de SDL_SetRenderDrawColor (%s)\n",SDL_GetError());
        return -1;
    }
    if(SDL_RenderClear(renderer) < 0) {
        fprintf(stdout,"Échec de SDL_RenderClear (%s)\n",SDL_GetError());
        return -1;
    }

    return 0;  
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
