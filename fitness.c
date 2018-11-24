#include "a4.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double comp_distance ( const PIXEL *A, const PIXEL *B, int image_size ) {
	// image_size is the number of pixels, each with 3 channels
	double d = 0;
	// do unrolling by 4 to optomize computation time !!!
	for (int i = 0; i < image_size; i++) {
		d += pow(((int) A[i].r - (int) B[i].r),2);
		d += pow(((int) A[i].b - (int) B[i].b),2);
		d += pow(((int) A[i].g - (int) B[i].g),2);
	}
	d = pow(d, 0.5);
	return d;

}
void comp_fitness_population ( const PIXEL *image , Individual *individual , int population_size ) {
	for (int i = 0; i < population_size; i++) {
		individual[i].fitness = comp_distance(individual[i].image.data, image, individual->image.width * individual->image.height);
	}
}
