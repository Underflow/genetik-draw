#define NB_GENES 100

typedef struct Color {
  unsigned char r, g, b, a;
} Color;

/*
 * This is a protein... or a circle definition
 */
typedef struct Protein {
  int x, y;
  Color color;
  int radius;
} Protein;

typedef struct Gene {
  unsigned char x, y;
  Color color;
  unsigned char radius;
} Gene;

typedef struct Individual {
  Gene gene[NB_GENES];
  int fitness;
} Individual;

typedef struct Population {
  int size;
  Individual* individual;
} Population;

Protein gene_translation(Gene gene, int screen_width, int screen_height);
void randomize_gene(Gene* gene);
