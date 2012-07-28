#include <stdio.h>
#include <stdlib.h>
#include "SDL/SDL.h"
#include "genome.h"

void sdl_loop()
{
  int exit = 0;
  SDL_Event event;
  while (!exit)
  {
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
  SDL_Init(SDL_INIT_VIDEO);
  SDL_SetVideoMode(800, 600, 32, SDL_HWSURFACE);
  sdl_loop();
  SDL_Quit();
  return EXIT_SUCCESS;
}
