Individual have_sex(Individual mother, Individual father);
void update_fitness(Individual* individual, SDL_Surface* reference_image);
Population generate_population(int size);
Individual generate_individual();
void draw_individual(SDL_Surface* surface, Individual individual, int screen_width, int screen_height);

