#include <stdlib.h>
#include "SDL/SDL.h"
#include "math.h"
#include "genome.h"
#include "genetic.h"
#include "draw.h"
/*
 * Process a crossover to create a new individual
 * [I have to document myself more to write the crossover function correctly]
 */
Individual have_sex(Individual mother, Individual father)
{
  Individual baby;
  for(int i = 0; i < NB_GENES; i++) {
    if(i % 2 == 0) {
      baby.gene[i] = mother.gene[i]; 
    } else {
      baby.gene[i] = father.gene[i];
    }
  }
  return baby;
}

/*
 * Draw a surface with the individual informations
 */
void draw_individual(SDL_Surface* surface, Individual individual, int screen_width, int screen_height)
{
  for(int i = 0; i < NB_GENES; i++)
  {
    Protein protein = gene_translation(individual.gene[i], surface->w, surface->h); 
    draw_protein(surface, protein); 
    //draw_disk(surface, protein.x, protein.y, protein.radius, pixel);
  }
}

/*
 * Update the fitness score of an individual
 */
void update_fitness(Individual* individual, SDL_Surface* reference_image)
{
  unsigned int sum = 0;
  SDL_Surface* surface = SDL_CreateRGBSurface(SDL_HWSURFACE, reference_image->w, reference_image->h, 32, 0, 0, 0, 0);
  SDL_FillRect(surface, NULL, SDL_MapRGB(surface->format, 0, 0, 0));
  draw_individual(surface, *individual, surface->w, surface->h);
  SDL_LockSurface(reference_image);
  SDL_LockSurface(surface);
  for(int x = 0; x < reference_image->w; x++) {
    for(int y = 0; y < reference_image->h; y++) {
      Uint8 r1, g1, b1, a1, r2, g2, b2, a2;
      get_pixel(surface, x, y, &r1, &g1, &b1, &a1);
      get_pixel(surface, x, y, &r2, &g2, &b2, &a2);
      sum+=abs(r1 - r2);
      sum+=abs(g1 - g2);
      sum+=abs(b1 - b2);
      sum+=abs(a1 - a2);
    }
  }
  SDL_UnlockSurface(reference_image);
  SDL_FreeSurface(surface);
  individual->fitness = sum;
}

/*
 * Generate a random population
 */
Population generate_population(int size)
{
  Population population;
  population.size = size;
  population.individual = malloc(sizeof(Individual) * size);
  for(int i = 0; i < size; i++) {
    population.individual[i] = generate_individual();
  }

  return population;
}

/*
 * Generate a random individual
 */
Individual generate_individual()
{
  Individual individual;
  individual.fitness = 0;
  //Randomize DNA
  for(int i = 0; i < NB_GENES; i++)
  {
    gene_randomization(&individual.gene[i]);
  }
  return individual;
}
