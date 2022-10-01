#ifndef FILTERS_H_
#define FILTERS_H_

struct img; typedef struct img img_t;
struct pixel; typedef struct pixel pixel_t;

enum ColorCvt {
  ColorCvt_Grayscale,
};

typedef enum ColorCvt ColorCvt_t;

/*
 * Applies a given ImageFilterFun callback function to a given image per pixel.
 * Data is a img_t*, and filter is a ImageFilterFun type.
 * FIXME: Make this a function.
 * */
#define apply_filter(img, filter, ...)                                         \
  for (unsigned char *i = (img)->data;                                         \
       i != (img)->data + (img)->h * (img)->w * (img)->n; i += (img)->n) {     \
    filter(img, (pixel_t *)i, __VA_ARGS__);                                    \
  }

void convert_color(img_t *img, pixel_t *p, ColorCvt_t cvt);
void flip(img_t *img, pixel_t *p, int dir);
void zmangus(img_t *img, pixel_t *p);

#endif //FILTERS_H_
