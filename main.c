#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "SDL/SDL.h"
#include "genome.h"
#include "genetic.h"

void genetic_loop(SDL_Surface* screen, SDL_Surface* model)
{
  int n_generation = 0;
  Population population;
  SDL_Surface* backbuffer = SDL_CreateRGBSurface(SDL_HWSURFACE, 
                                              screen->w,
                                              screen->h, 
                                              32, 0, 0, 0, 0); 
  generate_population(15, &population);
  evaluate_population(&population, model);
  int exit = 0;
  SDL_Event event;
  while (!exit) {
    SDL_FillRect(backbuffer, NULL, SDL_MapRGB(backbuffer->format, 255, 255, 255));
    evaluate_population(&population, model);
    if(n_generation%10 == 0)
      printf("Generation : %d - Best fitness : %f\n", n_generation, 100 - (population.individual[0].fitness / 255 / 3 / backbuffer->w / backbuffer->h) * 100);
    n_generation++;
    gang_bang(&population);
    mutate_population(&population);
    draw_individual(backbuffer, &population.individual[0]);
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
