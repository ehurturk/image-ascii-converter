#include <stdlib.h> /* srand() */
#include <time.h>   /* time() */

#include "filters/filters.h"
#include "image.h"

int main(int argc, char **argv) {
  srand(time(NULL));

  img_t img;
  read_image_from_file(&img, "./assets/shadows.jpeg");
  apply_filter(&img, convert_color, ColorCvt_Grayscale);
  write_to_file("./assets/edited.jpg", &img);
  free_img(&img);
}
