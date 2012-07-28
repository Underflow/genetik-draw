typedef struct Surface {
  int width;
  int height;
  unsigned int *pixels;
} Surface;

Surface* create_surface(int width, int height);
unsigned int get_pixel(Surface *surface, int x, int y);
void set_pixel(Surface *surface, int x, int y, unsigned int pixel);
unsigned int compare_surfaces(Surface *s1, Surface *s2);
