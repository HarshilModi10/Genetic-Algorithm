#include "a4.h"
#include <stdio.h>
#include <stdlib.h>

// int main(void) {
//   PPM_IMAGE *img = read_ppm("mcmaster.ppm");
//   PPM_IMAGE *img2 = read_ppm("mcmaster.ppm");
//   double distance = comp_distance(img->data, img2->data, img->width * img->height);
//   int population_size = 50;
//   //Individual* pop = generate_population(population_size, 100, 100, 255);
//   Individual* pop = generate_population(population_size, img->width, img->height, img->max_color);
//   printf("The distance between the 2 images are: %.3f.\n", distance);
//   write_ppm("out.ppm",img);
//   free_image(img);
//   free_image(img2);
//   free_population(pop, population_size);
//   exit(EXIT_SUCCESS);
// }
int main(void) {
  PPM_IMAGE *image = read_ppm("me.ppm");
  int population_size = 24; // greater than 10 is seg fault ??
  //int minute = 4000;
  int num_generations = 50000;//minute*60; // 4000 iterations per minute
  double rate = 3e-2;
  //char input_file = "";
  printf("\nFile new_out.ppm:\nSize: %dx%d, max color %d, pixels to mutate %d\n",
   image->width, image->height, image->max_color, (int)(rate/100*image->width*image->height));
  PPM_IMAGE * new_image = evolve_image ( image , num_generations , population_size , rate );
  write_ppm("new_out.ppm",new_image);
  free_image(image);
  free_image(new_image);
  exit(EXIT_SUCCESS);
}