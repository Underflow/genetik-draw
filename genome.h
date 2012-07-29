#ifndef GENOME
#define GENOME
#define NB_GENES 150

typedef struct Color {
  unsigned char r, g, b, a;
} Color;

/*
 * This is a protein. Not convinced ?
 */
typedef struct Protein {
  int x, y;
  Color color;
  int length;
} Protein;

typedef struct Gene {
  unsigned char x, y;
  Color color;
  unsigned char length;
  unsigned char recessive;
} Gene;

typedef struct Individual {
  Gene gene[NB_GENES];
  double fitness;
} Individual;

typedef struct Population {
  int size;
  Individual* individual;
} Population;


void translate_gene(Gene gene, int screen_width, int screen_height, Protein* protein);
void randomize_gene(Gene* gene);
void mutate_gene(Gene* gene);
#endif
