#include "SDL/SDL.h"
#include "draw.h"
#include "genome.h"

void get_pixel(SDL_Surface* surface, int x, int y, Uint8* r, Uint8* g, Uint8* b, Uint8* a)
{
  unsigned int *ptr = (unsigned int*)surface->pixels;
  int lineoffset = y * (surface->pitch / 4);
  Uint32 color = ptr[lineoffset + x];
  SDL_GetRGBA(color, surface->format, r, g, b, a);
}


void draw_protein(SDL_Surface* surface, Protein protein)
{
  SDL_Surface* tmp =  SDL_CreateRGBSurface(SDL_HWSURFACE, protein.length, protein.length, 32, 0, 0, 0, 0);
  SDL_FillRect(tmp, NULL, SDL_MapRGB(surface->format,
                                     protein.color.r,
                                     protein.color.g,
                                     protein.color.b));
  SDL_SetAlpha(tmp, SDL_SRCALPHA, protein.color.a);
  SDL_Rect rec;
  rec.x = protein.x - protein.length / 2;
  rec.y = protein.y - protein.length / 2;
  SDL_BlitSurface(tmp, NULL, surface, &rec);
  SDL_FreeSurface(tmp); 
}
