#include "a4.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double comp_distance ( const PIXEL *A, const PIXEL *B, int image_size ) {
	// image_size is the number of pixels, each with 3 channels
	double d = 0;
	// do unrolling by 4 to optomize computation time !!!
	double r, g, b,r2, g2, b2;
	int i;
	int reminder = image_si
	for (i = 0; i < image_size; i++) {
		// d += (((int) A[i].r - (int) B[i].r)*((int) A[i].r - (int) B[i].r));
		// d += (((int) A[i].b - (int) B[i].b)*((int) A[i].b - (int) B[i].b));
		// d += (((int) A[i].g - (int) B[i].g)*((int) A[i].g - (int) B[i].g));
		r = ((int) A[i].r - (int) B[i].r);
		b = ((int) A[i].b - (int) B[i].b);
		g = ((int) A[i].g - (int) B[i].g);
		d += pow(r, 2);
		d += pow(b, 2);
		d += pow(g, 2);

	}


	d = sqrt(d);
	return d;

}
void comp_fitness_population ( const PIXEL *image , Individual *individual , int population_size ) {
	
	int i;
	for (i = 0; i < population_size; i++) {
		individual[i].fitness = comp_distance(individual[i].image.data, image, individual->image.width * individual->image.height);
	}
}
