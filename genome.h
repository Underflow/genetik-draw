#define NB_GENES 20

typedef struct Gene {
  unsigned char x, y;
  unsigned char r, g, b;
  unsigned char radius;
} Gene;

typedef struct Individual {
  Gene gene[NB_GENES];
  int fitness;
} Individual;

Individual* generate_individual();
