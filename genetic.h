#ifndef GENETIC
#define GENETIC
#include "genome.h"

void have_sex(Individual* mother, Individual* father, Individual* baby);
void sort_population(Population* population);
void update_fitness(Individual* individual, SDL_Surface* model);
void generate_population(int size, Population* population);
void generate_individual(Individual* individual);
void draw_individual(SDL_Surface* surface, Individual* individual);
#endif

