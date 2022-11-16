#include <stdio.h>
#include <stdlib.h>

#include "filters/filters.h"
#include "image.h"


void write_to_file_from_ascii_art(const char* fp, ascii_art_t* txt) {
  FILE* file;
  file = fopen(fp, "w");
  
  for (int i = 0; i < txt->w; i++) {
    for (int j = 0; j < txt->h; j++) {
      // add the character to the file
      fputc(txt->data[j + txt->w * i], file);
    }
    fputc('\n', file);
  }
  fputc('\0', file);
  fclose(file);
}

int main(int argc, char **argv) {
  if (argc != 3) {
    printf("Usage: ./bin/out [INPUT IMAGE PATH] [OUTPUT IMAGE PATH]");
    return 1;
  }

  img_t img;
  read_image_from_file(&img, argv[1]);
  // apply_filter(&img, convert_color, ColorCvt_Grayscale);
  ascii_art_t* ascii_txt = convert_ascii(&img);
  write_to_file_from_ascii_art(argv[2], ascii_txt);

  free_img(&img);
  free(ascii_txt);
  free(ascii_txt->data);
}
