#include "SDL/SDL.h"
#include "draw.h"

void get_pixel(SDL_Surface* surface, int x, int y, Uint8* r, Uint8* g, Uint8* b, Uint8* a)
{
  unsigned int *ptr = (unsigned int*)surface->pixels;
  int lineoffset = y * (surface->pitch / 4);
  Uint32 color = ptr[lineoffset + x];
  SDL_GetRGBA(color, surface->format, r, g, b, a);
}


void draw_h_line(SDL_Surface* surface, int x, int y, int w, Uint32 color)
{
  SDL_Rect r;
  r.x = x;
  r.y = y;
  r.w = w;
  r.h = 1;
  
  SDL_FillRect(surface, &r, color);
}

void draw_disk(SDL_Surface* surface, int cx, int cy, int radius, Uint32 pixel)
{
    int d, y, x;
     
    d = 3 - (2 * radius);
    x = 0;
    y = radius;
           
    while (y >= x) {
      draw_h_line(surface, cx - x, cy - y, 2 * x + 1, pixel);
      draw_h_line(surface, cx - x, cy + y, 2 * x + 1, pixel);
      draw_h_line(surface, cx - y, cy - x, 2 * y + 1, pixel);
      draw_h_line(surface, cx - y, cy + x, 2 * y + 1, pixel);
      if (d < 0)
        d = d + (4 * x) + 6;
      else {
        d = d + 4 * (x - y) + 10;
        y--;
      }
      x++;
    }
}
