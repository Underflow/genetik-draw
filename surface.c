#include <stdlib.h>
#include "surface.h"

/*
 * Create a new surface
 */

Surface* create_surface(int width, int height)
{
  Surface s;
  s.width = width;
  s.height = height;
  s.pixels = malloc(sizeof(unsigned int) * width * height);
}

/*
 * Get the color of a pixel in a surface
 */
unsigned int get_pixel(Surface *surface, int x, int y)
{
  return surface->pixels[x + y * surface->width]; 
}

/*
 * Set the color of a pixel in a surface
 */
void set_pixel(Surface *surface, int x, int y, unsigned int pixel)
{
  surface->pixels[x + y * surface->width] = pixel;
}

/*
 * Compare two surfaces and return the sum of differences between each
 * pixels colors
 */
unsigned int compare_surfaces(Surface *s1, Surface *s2)
{
  
}
