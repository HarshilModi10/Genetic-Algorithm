// const char * file_name
#include <stdio.h>

typedef struct { 
	unsigned char r, g, b;
} PIXEL;

typedef struct {
	PIXEL * data ;
	int width , height ; 
	int max_color ;
} PPM_IMAGE ;

typedef struct {
	PPM_IMAGE image ; // image
	double fitness ; // fitness
} Individual ;

#include <stdio.h>
#include <stdlib.h>

// Reads a PPM image file and returns a pointer to a PPM_IMAGE structure containing the pixels
// of the image, width, height, and max color.
void read_ppm ( const char * file_name ) {
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
  int counter = 0;
  int width, height, max_color;
  while ((read = getline(&line, &len, fp)) != -1) {
      //printf("%s\n", line);
      if (counter == 0){
        if (line[0] != 'P' || line[1] != '3'){
          printf("Invalid file type.\n");
          exit(1);
        }
      } 
      else if (counter == 1){
        sscanf(line, "%d %d", &width, &height);
      }
      else if (counter == 2){
        sscanf(line, "%d", &max_color);
        break;
      } 
      counter++;
    } 
    int pixels [width*height] [3];
    int i = 0, offset, n, index = 0;
    while ((read = getline(&line, &len, fp)) != -1) { 
      //printf("%s\n", line);
      char* data = line;
      while (sscanf(data, " %d%n", &n, &offset) == 1){
        data += offset;
        pixels[i][index] = n;
        if (index == 2) index = 0; else index++;
        if (index == 0) i++;
        printf("%d ", n);
      }
      printf("\n");
    }
  //printf("%s", file_contents);
  printf("Dimensions are: %dx%d\nMax color: %d\n", width, height, max_color);
  printf("Check @ 0: (%d,%d,%d)\n", pixels[0][0], pixels[1][0], pixels[2][0]);
  printf("Done\n");
  free(line);

}


int main(void) {
    read_ppm("test2.txt");
    exit(EXIT_SUCCESS);
}

int main2(void) {
    char line1[] = "P3";
    char line2[] = "20 20";
    char line3[] = "210";
    char line[] = "100 185 400 11 1000";
    char *data = line;
    int num [20], i = 0, offset, n;
    int width, height, max_color;
    sscanf(line2, "%d %d", &width, &height);
    sscanf(line3, "%d", &max_color);
    printf("Dimensions are: %dx%d\nMax color: %d\n", width, height, max_color);
    while (sscanf(data, " %d%n", &n, &offset) == 1){
        num[i++] = n;
        data += offset;
    }
    printf("Value of i is: %d\n", i);
    for( int j = 0; j < i; j++) printf("%d\n",num[j]);
    printf("End of script\n");
    return 0;
    int pixels [width*height] [3];
        pixels[0][0] = 1;
        pixels[0][1] = 2;
        pixels[0][2] = 3;
}