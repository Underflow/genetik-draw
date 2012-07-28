#include <stdlib.h>
#include "SDL/SDL.h"
#include "genome.h"
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
 * Update the fitness score of an individual
 */
void update_fitness(Individual* individual, SDL_Surface reference_image)
{
  individual->fitness = 0;
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
    randomize_gene(&individual.gene[i]);
  }
  return individual;
}
