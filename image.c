#include "image.h"

#define STB_IMAGE_IMPLEMENTATION
#include "stb/stb_image.h"
#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "stb/stb_image_write.h"

int read_image_from_file(img_t *img, const char *filepath) {
  int w, h, n;
  unsigned char *data = stbi_load(filepath, &w, &h, &n, 0);
  if (!data) {
    stbi_image_free(data);
    return FILE_READ_FAILURE;
  }
  img->data = data;
  img->w = w;
  img->h = h;
  img->n = n;
  return 1;
}

int write_to_file(const char *filepath, img_t *data) {
  stbi_write_jpg(filepath, data->w, data->h, data->n, data->data, 100);
  return 1;
}

void free_img(img_t *img) { stbi_image_free(img->data); }
