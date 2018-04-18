#ifndef VIDEO_DRIVER__H
#define VIDEO_DRIVER__H

#include "font.h"

#include <stdint.h>

void load_vDriver();

int fill(char red, char green, char blue, int x, int y);
void clear();
int scr_x_res();
int scr_y_res();
int text_rows();
int text_cols();


#define SCREEN_HEIGHT y_res
#define SCREEN_WIDTH  x_res

#define HEIGHT (SCREEN_HEIGHT/CHAR_HEIGHT)
#define WIDTH (SCREEN_WIDTH/CHAR_WIDTH)

#define MAX_RGB 255
#define MIN_RGB 0

#define DEFAULT_CHAR_COLOR {255,255,255} // Blanco
#define DEFAULT_BG_COLOR {0,0,0}  // Negro

#endif
