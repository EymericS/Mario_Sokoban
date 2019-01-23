#include "header/fonction_texture.h"

Texture new_Texture( SDL_Renderer *renderer ) {
    Texture tmp;
    tmp.m_renderer = renderer;
    tmp.m_texture = NULL;
    tmp.m_rect.x = 0;
    tmp.m_rect.y = 0;
    tmp.m_rect.w = 0;
    tmp.m_rect.h = 0;
    return tmp;
}

void fonction_fromTxt( Texture *this, TTF_Font *font, const char *txt, SDL_Color color ) {
    SDL_Surface *tmp = TTF_RenderText_Solid(font, txt, color);
    this->m_texture = SDL_CreateTextureFromSurface(this->m_renderer, tmp);
    SDL_QueryTexture(this->m_texture, NULL, NULL, &this->m_rect.w, &this->m_rect.h);
    SDL_FreeSurface(tmp);
    //faire des verification ?
}

void fonction_print( Texture this ) {
    SDL_RenderCopy(this.m_renderer, this.m_texture, NULL, &this.m_rect);
}

/*

SDL_QueryTexture(txt, NULL, NULL, &txtRect.w, &txtRect.h);
    SDL_RenderCopy(renderer, txt, NULL, &txtRect);

    */