#include "header/menu.h"

int loop_menu( SDL_Renderer *renderer, Input *input ) {
    SDL_Color c1 = { 255, 0, 0, 255};
    SDL_Color c2 = { 0, 0, 255, 255};
    int c = 1, statut = EXIT_FAILURE;
    input->m_quit = SDL_FALSE;

    TTF_Font *arial_16 = NULL;
    arial_16 = TTF_OpenFont(ARIAL_TTF_PATH, 16);
    if( arial_16 == NULL ) {
        fprintf(stdout,"Échec de TTF_OpenFont(%s) : %s\n", ARIAL_TTF_PATH,TTF_GetError());
        goto Quit;
    }

    int iWidth, iHeight;
    char mot[] = "Niveau";
    SDL_Surface *tmp = TTF_RenderText_Blended(arial_16, mot, c2);
    SDL_Texture *txt = SDL_CreateTextureFromSurface(renderer, tmp);
    SDL_QueryTexture(txt, NULL, NULL, &iWidth, &iHeight);


    while(!input->m_quit) {
        updateEvent(input);
        if(input->m_key[SDL_SCANCODE_ESCAPE] == SDL_TRUE) {
            input->m_quit = SDL_TRUE;
        }

        if(c ==1) {
            setWindowColor(renderer, c1);
            SDL_RenderCopy(renderer, txt, NULL, NULL);
            //c = 2;
        }
        else {
            setWindowColor(renderer, c2);
            //c = 1;
        }

        SDL_RenderPresent(renderer);
        SDL_Delay(20);
    }
    if(0)
        goto Quit;

    statut = EXIT_SUCCESS;

Quit:
    if(arial_16 != NULL)
        TTF_CloseFont(arial_16);
    if(tmp != NULL)
        SDL_FreeSurface(tmp);
    if(txt != NULL)
        SDL_DestroyTexture(txt);

    return statut;
}