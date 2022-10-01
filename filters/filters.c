#include "filters.h"
#include "../image.h"

#include <math.h>
#include <stdio.h>

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

void zmangus(img_t *img, pixel_t *p) {}
