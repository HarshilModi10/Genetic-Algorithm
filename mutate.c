#include "a4.h"
#include <stdio.h>
#include <stdlib.h>

void mutate ( Individual * individual , double rate ) {
	// srand(time(NULL));
	int num_pixels = individual->image.width * individual->image.height;
	int num_selects = (int) (rate/100*num_pixels);
	int max_color = individual->image.max_color;
	for (int i = 0; i < num_selects; i++) {
		int pos = rand() % num_pixels;
		individual->image.data[pos].r = rand() % max_color;
		individual->image.data[pos].b = rand() % max_color;
		individual->image.data[pos].g = rand() % max_color;
	}
}

void mutate_population ( Individual * individual , int population_size , double rate ) {
	int i = (int) population_size/4;
	for (i; i < population_size; i++) {
		mutate((individual + i), rate);
	}
}