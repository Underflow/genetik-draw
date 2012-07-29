#ifndef GENETIC
#define GENETIC
#include "genome.h"

void have_sex(const Individual* mother, const Individual* father, Individual* baby);
void gang_bang(Population* population);
Individual* find_good_individual(Population* sorted_population);
void sort_population(Population* population);
void evaluate_population(Population* population, SDL_Surface* model);
void update_fitness(Individual* individual, SDL_Surface* model);
void mutate_population(Population* population);
void generate_population(int size, Population* population);
void generate_individual(Individual* individual);
void draw_individual(SDL_Surface* surface, Individual* individual);
#endif

