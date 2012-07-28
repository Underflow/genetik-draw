#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "SDL/SDL.h"
#include "genome.h"
#include "genetic.h"

void genetic_loop(SDL_Surface* screen, SDL_Surface* model)
{
  Individual i1 = generate_individual();
  SDL_Surface* backbuffer = SDL_CreateRGBSurface(SDL_HWSURFACE, 
                                              screen->w,
                                              screen->h, 
                                              32, 0, 0, 0, 0); 
  
  update_fitness(&i1, model);
  draw_individual(backbuffer, i1); 
 


  int exit = 0;
  SDL_Event event;
  while (!exit)
  {
    SDL_Rect pos;
    pos.x = 0;
    pos.y = 0;
    SDL_BlitSurface(backbuffer, NULL, screen, &pos); 
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
  SDL_Surface* model = SDL_LoadBMP("model.bmp");
  SDL_Surface* screen = SDL_SetVideoMode(model->w, model->h, 32, SDL_HWSURFACE);
  genetic_loop(screen, model);
  SDL_Quit();
  return EXIT_SUCCESS;
}
