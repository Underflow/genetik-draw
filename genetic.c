#include <stdlib.h>
#include "SDL/SDL.h"

Population generate_population(int size)
{
  Population population;
  population.size = size;
  population.individual = malloc(sizeof(Individual) * size);
  for(int i = 0; i < size; i++) {
    population.individual[i] = generate_individual();
  }
}
