#include <stdlib.h>
#include <math.h>
#include "genome.h"

/*
 * Pick a integer between [min;max[
 */
int rand_between(int min, int max) {
  return rand()%(max-min) +min;
}

/*
 * Translate a gene to make a protein
 * (Return a circle definition made from a gene)
 */
Protein gene_translation(Gene gene, int screen_width, int screen_height)
{
  Protein protein;
  protein.x = (int)((float)gene.x / 255 * screen_width);
  protein.y = (int)((float)gene.y / 255 * screen_height);
  protein.color = gene.color;
  //The radius is actually proportional to the half of screen diagonal
  protein.length = (int)((float)gene.length / 255 * sqrt(screen_width * screen_width + screen_height * screen_height)); 
  return protein;
}


/*
 * Randomize a single gene
 */
void gene_randomization(Gene* gene)
{
  gene->x = rand_between(0, 256);
  gene->y = rand_between(0, 256);
  Color c;
  c.r = rand_between(0, 256);
  c.g = rand_between(0, 256);
  c.b = rand_between(0, 256);
  c.a = rand_between(0, 256);
  gene->color = c;
  gene->length = rand_between(0, 256);
}

