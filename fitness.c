#include "a4.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double comp_distance ( const PIXEL *A, const PIXEL *B, int image_size ) {

	// image_size is the number of pixels, each with 3 channels
	double d = 0;
	// do unrolling by 2 to optomize computation time !!!
	double r, g, b,r2, g2, b2;
	int i;
	int reminder = image_size%2;
	for (i = 0; i < image_size; i+=2) {

		r = ((int) A[i].r - (int) B[i].r);
		b = ((int) A[i].b - (int) B[i].b);
		g = ((int) A[i].g - (int) B[i].g);
		d += (r*r);
		d += (b*b);
		d += (g*g);

		r2 = ((int) A[i + 1].r - (int) B[i + 1].r);
		b2 = ((int) A[i + 1].b - (int) B[i + 1].b);
		g2 = ((int) A[i+1].g - (int) B[i+1].g);
		d += (r2*r2);
		d += (b2*b2);
		d += (g2*g2);

	}

	// Add the last Pixel if image_size is odd
	if(reminder == 1){
		r = ((int) A[image_size -1].r - (int) B[image_size -1].r);
		b = ((int) A[image_size -1].b - (int) B[image_size -1].b);
		g = ((int) A[image_size -1].g - (int) B[image_size -1].g);
		d += (r*r);
		d += (b*b);
		d += (g*g);
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
