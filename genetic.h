#ifndef GENETIC
#define GENETIC
#include "genome.h"

void have_sex(const Individual* mother, const Individual* father, Individual* baby);
void sort_population(Population* population);
void update_fitness(Individual* individual, SDL_Surface* model);
void mutate_population(Population* population);
void generate_population(int size, Population* population);
void generate_individual(Individual* individual);
void draw_individual(SDL_Surface* surface, Individual* individual);
#endif

