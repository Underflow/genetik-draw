#define NB_GENES 20

/*
 * This is a protein... or a circle definition
 */
typedef struct Protein {
  int x, y;
  unsigned int color;
  int radius;
} Protein;

typedef struct Gene {
  unsigned char x, y;
  unsigned int  color;
  unsigned char radius;
} Gene;

typedef struct Individual {
  Gene gene[NB_GENES];
  int fitness;
} Individual;

Protein gene_translation(Gene gene, int screen_width, int screen_height);
void randomize_gene(Gene* gene);
Individual generate_individual();
