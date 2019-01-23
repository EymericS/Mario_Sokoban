#include "header/menu.h"

int loop_menu( SDL_Renderer *renderer, Input *input ) {
    int statut = EXIT_FAILURE;
    
    char mot[] = "Une phrase un peut plus longue";

    Texture texte = new_Texture(renderer);
    fonction_fromTxt(&texte, ARIAL_16, mot, COLOR_RED);
    texte.m_rect.x = (WINDOW_WIDTH - texte.m_rect.w)/2;
    texte.m_rect.y = (WINDOW_HEIGHT - texte.m_rect.h)/2;

    input->m_quit = SDL_FALSE;
    while(!input->m_quit) {
        input->updateEvent(input);
        if(input->m_key[SDL_SCANCODE_ESCAPE] == SDL_TRUE) {
            input->m_quit = SDL_TRUE;
        }

        setWindowColor(renderer, COLOR_GRAY);
        SDL_RenderClear(renderer);
        fonction_print(texte);
        SDL_RenderPresent(renderer);
        SDL_Delay(20);
    }
    if(0)
        goto Quit;

    statut = EXIT_SUCCESS;

Quit:
    /*if(arial_16 != NULL)
        TTF_CloseFont(arial_16);*/
    /*if(tmp != NULL)
        SDL_FreeSurface(tmp);
    if(txt != NULL)
        SDL_DestroyTexture(txt);*/

    return statut;
}