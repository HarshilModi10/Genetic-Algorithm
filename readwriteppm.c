#include "a4.h"
#include <stdio.h>
#include <stdlib.h>

void updateColors(PPM_IMAGE *img, int dim, unsigned char pixels[][dim]) {
  int i;
  if (img) {
    for (i = 0; i < img->width * img->height; i++) {
      img->data[i].r = pixels[i][0];
      img->data[i].g = pixels[i][1];
      img->data[i].b = pixels[i][2];
    }
  }
}

// Reads a PPM image file and returns a pointer to a PPM_IMAGE structure
PPM_IMAGE *read_ppm(const char *file_name) {
  // setup for reading the input file
  FILE *fp;
  char *line = NULL;
  size_t len = 0;
  ssize_t read;

  fp = fopen(file_name, "r");
  if (fp == NULL)
    exit(EXIT_FAILURE);
  char *file_contents;
  size_t front;

  // variables for processing
  int counter = 0;                 // for processing the first 3 lines
  int width, height, max_color;    // variables for the image class
  int i = 0, offset, n, index = 0; // properties for sscanf
  while ((read = getline(&line, &len, fp)) != -1) {
    if (counter == 0) {
      if (line[0] != 'P' || line[1] != '3') {
        printf("Invalid file type.\n");
        exit(1);
      }
    } else if (counter == 1) {
      sscanf(line, "%d %d", &width, &height);
    } else if (counter == 2) {
      sscanf(line, "%d", &max_color);
      break;
    }
    counter++;
  }
  unsigned char pixels[width * height][3];
  while ((read = getline(&line, &len, fp)) != -1) {
    char *data = line;
    while (sscanf(data, " %d%n", &n, &offset) == 1) {
      data += offset;
      pixels[i][index] = n;
      if (index == 2)
        index = 0;
      else
        index++;
      if (index == 0)
        i++; // printf("%d ", n);
    }        // printf("\n");
  }
  free(line);
  fclose(fp);

  PPM_IMAGE *image;
  image = (PPM_IMAGE *)malloc(sizeof(PPM_IMAGE));
  image->width = width;
  image->height = height;
  image->max_color = max_color;
  image->data = (PIXEL *)malloc(image->width * image->height * sizeof(PIXEL));
  updateColors(image, 3, pixels);

  return image;
}

void write_ppm ( const char * file_name , const PPM_IMAGE * image ) {
  int num;

  FILE *fp = fopen(file_name, "w");

  if (!fp)
    exit(1);

  fprintf(fp, "P3\n%d %d\n%d\n", image->width, image->height, 255);

  for (int i = 0; i < image->height; i++) {
    for (int j = 0; j < image->width; j++) {
      fprintf(fp, "%d %d %d ", image->data[i * image->width + j].r,
              image->data[i * image->width + j].g,
              image->data[i * image->width + j].b);
    }
    if (i + 1 != image->height)
      fprintf(fp, "\n");
  }
  fclose(fp);
}

