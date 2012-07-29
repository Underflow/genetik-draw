#include <stdlib.h>
#include "SDL/SDL.h"
#include "math.h"
#include "genome.h"
#include "genetic.h"
#include "draw.h"
/*
 * Process a crossover to create a new individual
 */
void have_sex(const Individual* mother, const Individual* father, Individual* baby)
{
  for(int i = 0; i < NB_GENES; i++) {
      if(rand() % 2 == 0)
      baby->gene[i] = father->gene[i];
      else
        baby->gene[i] = mother->gene[i];
  }
}

/*
 * Find a good individual in a sorted population
 */
Individual* find_good_individual(Population* sorted_population)
{
  for(int i = 0; i < sorted_population->size; i ++)
    if(rand() % 2 == 0) {
      return &sorted_population->individual[i];
    }
  return &sorted_population->individual[0]; /* this could happend on 
                                               a small population */
}

/*
 * Generate a new population
 */
void gang_bang(Population* population)
{
  sort_population(population);
  Population new_population;
  new_population.size = population->size;
  new_population.individual = malloc(sizeof(Individual) * population->size);
  
  for(int i = 0; i < population->size; i++) {
    have_sex(find_good_individual(population),
             find_good_individual(population),
             &new_population.individual[i]); 
  }
  free(population->individual);
  *population = new_population;
}

/*
 * Draw a surface with the individual informations
 */
void draw_individual(SDL_Surface* surface, Individual* individual)
{
  for(int i = 0; i < NB_GENES; i++) {
    Protein protein;
    translate_gene(individual->gene[i], surface->w, surface->h, &protein); 
    draw_protein(surface, protein);
  }
}

/*
 * Sort a population in function of fitness
 */
void sort_population(Population* population)
{
  int i, j;
  for(int i = 1; i < population->size; ++i) {
    Individual k = population->individual[i];
    for(j = i; j > 0 && population->individual[j-1].fitness > k.fitness; j--)
      population->individual[j] = population->individual[j-1];
    population->individual[j] = k;
  }
}

/*
 * Mutate the whole genes of a population
 */
void mutate_population(Population* population)
{
  for(int i = 0; i < population->size; i++) {
    //Swap genes
    if(rand() % 2 == 0) {
      int g1 = rand_between(0, NB_GENES);
      int g2 = rand_between(0, NB_GENES);

      Gene tmp = population->individual[i].gene[g1];
      population->individual[i].gene[g1] = population->individual[i].gene[g2];
      population->individual[i].gene[g2] = tmp;
    }
    
    //Gene mutation
    for(int j = 0; j < NB_GENES; j++) {
      mutate_gene(&population->individual[i].gene[j]);
    }
  }
}

/*
 * Evaluate the adaptation of the generation to the problem
 */
void evaluate_population(Population* population, SDL_Surface* model)
{
  for(int i = 0; i < population->size; i++)
    update_fitness(&population->individual[i], model);
}

/*
 * Update the fitness score of an individual
 */
void update_fitness(Individual* individual, SDL_Surface* model)
{
  unsigned int sum = 0;
  SDL_Surface* surface = SDL_CreateRGBSurface(SDL_HWSURFACE, model->w, model->h, 32, 0, 0, 0, 0);
  SDL_FillRect(surface, NULL, SDL_MapRGB(surface->format, 0, 0, 0));
  draw_individual(surface, individual);
  SDL_LockSurface(model);
  SDL_LockSurface(surface);
  for(int x = 0; x < model->w; x++) {
    for(int y = 0; y < model->h; y++) {
      Uint8 r1, g1, b1, a1, r2, g2, b2;
      get_pixel_rgb(surface, x, y, &r1, &g1, &b1);
      get_pixel_rgb(model, x, y, &r2, &g2, &b2);
      int r_delta=abs(r1 - r2);
      int g_delta=abs(g1 - g2);
      int b_delta=abs(b1 - b2);
      sum+=r_delta + g_delta + b_delta;
    }
  }
  SDL_UnlockSurface(model);
  SDL_FreeSurface(surface);
  individual->fitness = sum;
}


/*
 * Generate a random population
 */
void generate_population(int size, Population* population)
{
  population->size = size;
  population->individual = malloc(sizeof(Individual) * size);
  for(int i = 0; i < size; i++)
    generate_individual(&population->individual[i]);
}

/*
 * Generate a random individual
 */
void generate_individual(Individual* individual)
{
  individual->fitness = 0;
  //Randomize DNA
  for(int i = 0; i < NB_GENES; i++) {
    randomize_gene(&individual->gene[i]);
  }
}
