#include <stdio.h>
#include <stdlib.h>
#include "genome.h"

int main()
{
  Individual *individual = generate_individual(); 
  free(individual);
  return 0;
}
