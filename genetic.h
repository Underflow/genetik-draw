#ifndef GENETIC
#define GENETIC
#include "genome.h"

Individual have_sex(Individual mother, Individual father);
void sort_population(Population* population);
void update_fitness(Individual* individual, SDL_Surface* model);
Population generate_population(int size);
Individual generate_individual();
void draw_individual(SDL_Surface* surface, Individual individual);
#endif

