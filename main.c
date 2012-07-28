#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "SDL/SDL.h"
#include "genome.h"
#include "genetic.h"

void sdl_loop(SDL_Surface* screen)
{
  Individual i1 = generate_individual();
  SDL_Surface* drawing = SDL_CreateRGBSurface(SDL_HWSURFACE, screen->w, screen->h, 32, 0, 0, 0, 0); 
  SDL_FillRect(drawing, NULL, SDL_MapRGB(screen->format, 0, 0, 0));
  SDL_LockSurface(drawing);
  draw_individual(drawing, i1, screen->w, screen->h); 
  SDL_UnlockSurface(drawing);
  int exit = 0;
  SDL_Event event;
  while (!exit)
  {
    SDL_Rect pos;
    pos.x = 0;
    pos.y = 0;
    SDL_BlitSurface(drawing, NULL, screen, &pos); 
    SDL_Flip(screen);
    SDL_PollEvent(&event);
    switch(event.type)
    {
      case SDL_QUIT:
      exit = 1;
     }
  }
}

int main()
{
  srand(time(NULL));
  SDL_Init(SDL_INIT_VIDEO);
  SDL_Surface* screen = SDL_SetVideoMode(600, 480, 32, SDL_HWSURFACE);
  sdl_loop(screen);
  SDL_Quit();
  return EXIT_SUCCESS;
}
