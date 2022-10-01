#ifndef IMAGE_H_
#define IMAGE_H_

#define FILE_READ_FAILURE 0

struct img {
    unsigned char *data;
    unsigned int w, h, n;
};

typedef struct img img_t;

struct pixel {
    unsigned char r, g, b;
};

typedef struct pixel pixel_t;

/*
 * Loads image based on the filepath.
 */
int read_image_from_file(img_t *img, const char *filepath);

/*
 * Writes image to a file.
 */
int write_to_file(const char *filepath, img_t *data);

/*
 * Releases the image.
 */
void free_img(img_t *img);


#endif //IMAGE_H_
