#include "filters.h"
#include "../image.h"

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

void convert_color(img_t *img, pixel_t *p, ColorCvt_t cvt) {
  switch (cvt) {
  case ColorCvt_Grayscale: {
    float g = sqrt((p->r * p->r + p->g * p->g + p->b * p->b) / 3.0f);
    p->r = g;
    p->g = g;
    p->b = g;
    break;
  }
  default:
    printf("No such color conversion exists...\n");
    break;
  }
}

void flip(img_t *img, pixel_t *p, int dir) {
  int w = img->w, h = img->h; /* 500, 400 */
  p->r *= dir;
  p->g *= dir;
  p->b *= dir;
}

ascii_art_t* convert_ascii(img_t *img) {
  ascii_art_t* art = malloc(sizeof(ascii_art_t));
  char map[10] = " .,:;ox%#@"; // a sorted intensity array
  unsigned char *i = img->data;
  printf("img->n = %d\n", img->n);
  printf("img->w = %d\n", img->w);
  printf("img->h = %d\n", img->h);
  printf("img->data[0] = %d\n", img->data[0]);

  char *ascii_img = calloc(img->w * img->h * img->n, sizeof(char) * img->w * img->h * img->n); // TODO: Release the resource.

  for (int y = 0; y < img->w; y++) {
    for (int x = 0; x < img->h; x++) {
      const int pixel_index = (x + y * img->w) * img->n;
      int r, g, b;
      r = img->data[pixel_index + 0]; 
      g = img->data[pixel_index + 1]; 
      b = img->data[pixel_index + 2];
      const int intensity = (r + g + b) / 3;
      char t = map[(255 - intensity) * 10 / 256];
      ascii_img[y*img->w + x] = t;
      i += img->n;
    }
  }
  
  art->data = ascii_img;
  art->w = img->w;
  art->h = img->h;

  return art;
}
