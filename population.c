#include "a4.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

PIXEL *generate_random_image(int width, int height, int max_color){


    int population_size = width * height, i;

    //Allocating memory for population
    PIXEL* image = (PIXEL *)malloc(population_size*sizeof(PIXEL));

    //random pixel values for population
    for (i = 0; i <population_size; i++){
      
      image[i].r = rand() % max_color;
      image[i].g = rand() % max_color;
      image[i].b = rand() % max_color;
    }

    return image;
}

Individual *generate_population(int population_size, int width, int height, int max_color){
  //srand(time(NULL));

  //Allocating memory for generation of population
  Individual* population = (Individual *)malloc(population_size*sizeof(Individual));

  //Initalizing each population
  for(int i = 0; i < population_size; i++){
    population[i].image.width = width;
    population[i].image.height = height;
    population[i].image.max_color = max_color;
    population[i].image.data = generate_random_image(width,height,max_color);
  }

  return population;

}