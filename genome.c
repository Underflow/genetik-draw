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
  protein.x = (gene.x / 255) * screen_width;
  protein.y = (gene.y / 255) * screen_height;
  protein.color = gene.color;
  //The radius is actually proportional to the half of screen diagonal
  protein.radius = (gene.radius / 255) * sqrt(screen_width * screen_width + screen_height * screen_height) / 2; 
}


/*
 * Randomize a single gene
 */
void randomize_gene(Gene* gene)
{
  gene->x = 0;
  gene->y = 0;
  Color c;
  c.r = 0;
  c.g = 0;
  c.b = 0;
  c.a = 0;
  gene->color = c;
  gene->radius = 0;
}

