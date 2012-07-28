#include <stdlib.h>
#include <math.h>
#include "genome.h"

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
  protein.radius = (int)((float)gene.radius / 255 * sqrt(screen_width * screen_width + screen_height * screen_height) / 2); 
  return protein;
}


/*
 * Randomize a single gene
 */
void gene_randomization(Gene* gene)
{
  gene->x = 100;
  gene->y = 100;
  Color c;
  c.r = 255;
  c.g = 255;
  c.b = 255;
  c.a = 255;
  gene->color = c;
  gene->radius = 50;
}

