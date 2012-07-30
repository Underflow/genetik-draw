#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "SDL/SDL.h"
#include "genome.h"
#include "genetic.h"

void genetic_loop(SDL_Surface* model)
{
  int n_generation = 0;
  Population population;
  SDL_Surface* output_surface = SDL_CreateRGBSurface(SDL_SWSURFACE, 
                                              model->w,
                                              model->h, 
                                              32, 0, 0, 0, 0); 
  generate_population(30, &population);
evaluate_population(&population, model);
  int exit = 0;
  SDL_Event event;
  while (!exit) {
    SDL_FillRect(output_surface, NULL, SDL_MapRGB(output_surface->format, 0, 0, 0));
    evaluate_population(&population, model);
    sort_population(&population);
    if(n_generation%10 == 0)
    {
      FILE *f = fopen("log.txt", "w");
      fprintf(f, "Generation : %d - Best fitness : %f\n", n_generation, 100 - (population.individual[0].fitness / 255 / 3 / output_surface->w / output_surface->h) * 100);
      fclose(f);
    }
      n_generation++;
    gang_bang(&population);
    draw_individual(output_surface, &population.individual[0]);
    if(n_generation % 10 == 0)
      SDL_SaveBMP(output_surface, "output.bmp");
    mutate_population(&population);
  }
}

int main()
{
  srand(time(NULL));
  SDL_Surface* model = SDL_LoadBMP("model.bmp");
  genetic_loop(model);
  SDL_Quit();
  return EXIT_SUCCESS;
}
