#include "SDL/SDL.h"
#include "draw.h"
#include "genome.h"

/*
 * Get the color of a pixel in a SDL_Surface
 */
Uint32 get_pixel(SDL_Surface *surface, int x, int y)
{
  int bpp = surface->format->BytesPerPixel;
  Uint8 *p = (Uint8 *)surface->pixels + y * surface->pitch + x * bpp;
  switch(bpp) {
    case 1:
      return *p;
      break;
    case 2:
      return *(Uint16 *)p;
      break;
    case 3:
      if(SDL_BYTEORDER == SDL_BIG_ENDIAN)
        return p[0] << 16 | p[1] << 8 | p[2];
      else
        return p[0] | p[1] << 8 | p[2] << 16;
      break;
    case 4:
      return *(Uint32 *)p;
      break;
    default:
      return 0;       /* shouldn't happen, but avoids warnings */
  }
}

/*
 * Get the color of a pixel in a SDL_Surface
 */
void get_pixel_rgb(SDL_Surface* surface, int x, int y, Uint8* r, Uint8* g, Uint8* b)
{
  SDL_GetRGB(get_pixel(surface, x, y), surface->format, r, g, b);
}

/*
 * Draw a square using protein informations
 */
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
