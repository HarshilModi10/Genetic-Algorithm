#include "a4.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <math.h>

void free_population(Individual * p, int population_size);
void updateChannels(PPM_IMAGE *img, Individual * p);

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
	double original = first, temp;
	int img_dim = image->width * image->height;

	//FILE *data=fopen("data-alr-99992-wmin.txt", "a");
	int count = 1;
    char num[10], file[50];
    double adaptivelr = rate; // * here
    double const_rate = rate*(0.2);

    
	for (int i = 0; i < num_generations; i++) {
		
		crossover(population, population_size);
		mutate_population ( population , population_size , adaptivelr ); // * here
		comp_fitness_population ( image->data , population , population_size );
		qsort (population, population_size, sizeof(Individual), compare);
		temp = population[0].fitness;
		if ((i + 1)% 100 == 0) {
			
			printf("Iteration: %d - P.Change (last): %.2e%%; P.Change (first): %.3f%%; Fitness: %.5e; Num Pixels: %d\n", i+1, (temp-first)/first*100,100. + (temp-original)/original*100, temp, (int) ((adaptivelr/100)*55224));
			//fprintf(data, "%.3f ", 100. + (temp-original)/original*100);
			adaptivelr = pow(0.99993,(int) (i+1/100))*rate; // *here 
			if (((int)((adaptivelr/100)*img_dim)) == 0) adaptivelr = const_rate;
		}

		first = population[0].fitness;

		// if ((i + 1) % 50 == 0) {
  //   		strcpy(file, "vids/img");
  //   		sprintf(num, "%04d", count++);
		// 	strcat(file, num);
		// 	strcat(file,".ppm");
		// 	write_ppm(file,&(population[0].image));
		// }

	}
	//fclose(data);
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