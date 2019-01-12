#ifndef _CONSTANTES_H_
#define _CONSTANTES_H_

/**
 * \file constantes.h
 * \brief Définitions des constantes du programme
 * \author Eymeric S.
 * \version 1.0
 * \date 4 janvier 2019
 * 
 * Fichier contenant toutes les constantes du programme
 * 
 * Largement inspiré du code de mateo21 ( pour le site du zero )
 * 
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>

#define BLOCK_WIDTH 34
#define BLOCK_HEIGHT 34
#define WIDTH_BLOC_NUMBER 12
#define HEIGHT_BLOC_NUMBER 12
#define WINDOW_WIDTH BLOCK_WIDTH * WIDTH_BLOC_NUMBER
#define WINDOW_HEIGHT BLOCK_HEIGHT * HEIGHT_BLOC_NUMBER

#define ARIAL_TTF_PATH "asset/font/arial.ttf"

enum { HAUT, BAS, GAUCHE, DROITE};
enum { VIDE, MUR, CAISSE, CAISSE_OK, OBJECTIF, MARIO};

#endif