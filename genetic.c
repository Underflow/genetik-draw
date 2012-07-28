#include <stdlib.h>
#include "SDL/SDL.h"
#include "math.h"
#include "genome.h"
#include "genetic.h"
/*
 * Process a crossover to create a new individual
 * [I have to document myself more to write the crossover function correctly]
 */
Individual have_sex(Individual mother, Individual father)
{
  Individual baby;
  for(int i = 0; i < NB_GENES; i++) {
    if(i % 2 == 0) {
      baby.gene[i] = mother.gene[i]; 
    } else {
      baby.gene[i] = father.gene[i];
    }
  }
  return baby;
}

/*
 * Draw a surface with the individual informations
 */
void draw_individual(SDL_Surface* surface, Individual individual, int screen_width, int screen_height)
{
  for(int i = 0; i < 1; i++)
  {
    Protein protein = gene_translation(individual.gene[i], surface->w, surface->h); 
    Uint32 pixel = SDL_MapRGBA(surface->format, protein.color.r, protein.color.g, protein.color.b, protein.color.a);
    printf("Draw circle\n");
    printf("Position - X : %d Y : %d\n", protein.x, protein.y);
    printf("Pixel color : %d, %d, %d\n", protein.color.r, protein.color.g, protein.color.a);
    int cx = protein.x;
    int cy = protein.y;

    double r = (double)protein.radius;
    printf("Radius : %f\n", r);
    for (double dy = 1; dy <= r; dy += 1.0)
    {
      double dx = floor(sqrt((2.0 * r * dy) - (dy * dy)));
      int x = cx - dx;
      Uint8 *target_pixel_a = (Uint8 *)surface->pixels + ((int)(cy + r - dy)) * surface->pitch + x * 4;
      Uint8 *target_pixel_b = (Uint8 *)surface->pixels + ((int)(cy - r + dy)) * surface->pitch + x * 4;
      for (; x <= cx + dx; x++)
      {
        *(Uint32 *)target_pixel_a = pixel;
        *(Uint32 *)target_pixel_b = pixel;
        target_pixel_a += 4;
        target_pixel_b += 4;
      }
    }
  }
}

void get_pixel(SDL_Surface* surface, int x, int y, Uint8* r, Uint8* g, Uint8* b, Uint8* a)
{
  unsigned int *ptr = (unsigned int*)surface->pixels;
  int lineoffset = y * (surface->pitch / 4);
  Uint32 color = ptr[lineoffset + x];
  SDL_GetRGBA(color, surface->format, r, g, b, a);
}


/*
 * Update the fitness score of an individual
 */
void update_fitness(Individual* individual, SDL_Surface* reference_image)
{
  unsigned int sum = 0;
  SDL_Surface* surface = SDL_CreateRGBSurface(SDL_HWSURFACE, reference_image->w, reference_image->h, 32, 0, 0, 0, 0);
  SDL_FillRect(surface, NULL, SDL_MapRGB(surface->format, 0, 0, 0));
  SDL_LockSurface(surface);
  SDL_LockSurface(reference_image);
  draw_individual(surface, *individual, surface->w, surface->h);
  for(int x = 0; x < reference_image->w; x++) {
    for(int y = 0; y < reference_image->h; y++) {
      Uint8 r1, g1, b1, a1, r2, g2, b2, a2;
      get_pixel(surface, x, y, &r1, &g1, &b1, &a1);
      get_pixel(surface, x, y, &r2, &g2, &b2, &a2);
      sum+=abs(r1 - r2);
      sum+=abs(g1 - g2);
      sum+=abs(b1 - b2);
      sum+=abs(a1 - a2);
    }
  }
  SDL_UnlockSurface(reference_image);
  SDL_FreeSurface(surface);
  individual->fitness = sum;
}

/*
 * Generate a random population
 */
Population generate_population(int size)
{
  Population population;
  population.size = size;
  population.individual = malloc(sizeof(Individual) * size);
  for(int i = 0; i < size; i++) {
    population.individual[i] = generate_individual();
  }

  return population;
}

/*
 * Generate a random individual
 */
Individual generate_individual()
{
  Individual individual;
  individual.fitness = 0;
  //Randomize DNA
  for(int i = 0; i < NB_GENES; i++)
  {
    gene_randomization(&individual.gene[i]);
  }
  return individual;
}
