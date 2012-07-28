#ifndef DRAW
#define DRAW
#include "genome.h"

Uint32 get_pixel(SDL_Surface *surface, int x, int y);
void get_pixel_rgb(SDL_Surface* surface, int x, int y, Uint8* r, Uint8* g, Uint8* b);
void draw_protein(SDL_Surface* surface, Protein protein);
#endif
