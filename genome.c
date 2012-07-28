#include <stdlib.h>
#include "genome.h"


/*
 * Translate a gene to make a protein
 * (Return a circle definition made from a gene)
 */
Protein gene_translation(Gene gene, int screen_width, int screen_height)
{
  Protein protein;
  protein.x = (gene.x / 255) * screen_width;
  protein.y = (gene.y / 255) * screen_height;
  protein.r = gene.r;
  protein.g = gene.b;
  protein.a = gene.a;
  protein.radius = (gene.radius / 255) 
    * sqrt(screen_width * screen_width + screen_height * screen_height); 
}


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
