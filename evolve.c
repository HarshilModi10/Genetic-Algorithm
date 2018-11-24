#include "a4.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int compare (const void * a, const void * b)
{
	return (*(Individual *)a).fitness - (*(Individual *)b).fitness;
}
PPM_IMAGE * evolve_image ( const PPM_IMAGE *image , int num_generations ,int population_size , double rate ) {
	//srand(time(NULL));
	Individual* population = generate_population(population_size, image->width, image->height, image->max_color);
	comp_fitness_population ( image->data , population , population_size );
	qsort (population, population_size, sizeof(Individual), compare);
	double first = population[0].fitness;
	// ///////
	// // for (int i = 0; i < population_size; i++){
	// // 	printf("Fitness %d: %.3f\n", i+1, population[i].fitness);
	// // }
	for (int i = 0; i < num_generations; i++) {
		crossover(population, population_size);
		mutate_population ( population , population_size , rate );
		comp_fitness_population ( image->data , population , population_size );
		qsort (population, population_size, sizeof(Individual), compare);
		if ((i + 1)% 1 == 0) printf("Iteration %d: %.2e%\n", i+1, (population[0].fitness-first)/first*100);
		first = population[0].fitness;

	}
	PPM_IMAGE * final = (PPM_IMAGE *)malloc(sizeof(PPM_IMAGE));
	final->width = population[0].image.width;
	final->height = population[0].image.height;
	final->max_color = population[0].image.max_color;
	final->data = (PIXEL *)malloc(image->width * image->height * sizeof(PIXEL));
	updateChannels(final, population);
	free_population(population, population_size);
	return final;
}

void updateChannels(PPM_IMAGE *img, Individual * p) {
	for (int i = 0; i < img->width * img->height; i++) {
	  img->data[i].r = p[0].image.data[i].r;
	  img->data[i].g = p[0].image.data[i].g;
	  img->data[i].b = p[0].image.data[i].b;
	}
}

void free_population(Individual * p, int population_size) {

	for(int i =  0; i < population_size; i++){
		PPM_IMAGE * img = &(p[i].image); 
		PIXEL * data = img->data;
		free(data); 
	} 
	free(p);
}

void free_image (PPM_IMAGE *p) {
	PIXEL * data = p->data;
	free(data);
	free(p);
}