#ifndef DRAW
#define DRAW
#include "genome.h"

void get_pixel(SDL_Surface* surface, int x, int y, Uint8* r, Uint8* g, Uint8* b, Uint8* a);
void draw_protein(SDL_Surface* surface, Protein protein);
#endif
