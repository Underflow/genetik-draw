#include <stdlib.h>
#include <stdio.h>
#include "genome.h"


/*
 * Randomize a single gene
 */
void randomize_gene(Gene* gene)
{
  gene->x = 0;
  gene->y = 0;
  gene->r = 0;
  gene->b = 0;
  gene->radius = 0;
}

/*
 * Generate a random individual
 */
Individual* generate_individual()
{
  Individual *individual = malloc(sizeof(Individual));
  individual->fitness = 0;
  //Randomize DNA
  for(int i = 0; i < NB_GENES; i++)
  {
    randomize_gene(&individual->gene[i]);
  }
  return individual;
}
