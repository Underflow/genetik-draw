#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "SDL/SDL.h"
#include "genome.h"
#include "genetic.h"

void genetic_loop(SDL_Surface* screen, SDL_Surface* model)
{
  Individual i1;
  SDL_Surface* backbuffer = SDL_CreateRGBSurface(SDL_HWSURFACE, 
                                              screen->w,
                                              screen->h, 
                                              32, 0, 0, 0, 0); 

  int exit = 0;
  SDL_Event event;
  int i = 0;
  while (!exit) {
    i++;
    generate_individual(&i1);
    update_fitness(&i1, model);
    draw_individual(backbuffer, &i1);
    
    //Display the backbuffer
    SDL_BlitSurface(backbuffer, NULL, screen, NULL); 
    SDL_Flip(screen);
    //Handle events
    SDL_PollEvent(&event);
    switch(event.type)
    {
      case SDL_QUIT:
      exit = 1;
    }
    sleep(1);
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
