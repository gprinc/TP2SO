#include "videoDriver.h"
#include "strings.h"
#include "font.h"
#include "lib.h"

typedef struct {
	unsigned char red, green, blue;
} color;

static int cursor = 0;
static int x_res = 0;
static int y_res = 0;

static int valid_pixel(int x, int y);
static unsigned char * video_base_ptr();
static int get_res(unsigned char * ptr);
static int valid_colors(uint64_t r, uint64_t g, uint64_t b);
static void fillChar(int x, int y);
static void fillBackground(int x, int y);

static color char_color = DEFAULT_CHAR_COLOR;
static color bg_color = DEFAULT_BG_COLOR;

static unsigned char * video_base_ptr() {
	unsigned char ** VBEPhysBasePtr = (unsigned char**) 0x0005C28;
	return * VBEPhysBasePtr;
}

/* Retorna la resolucion de la pantalla(horizontal) */
int scr_x_res() {
	return x_res;
}

/* Retorna la resolucion de la pantalla(vertical) */
int scr_y_res() {
	return y_res;
}
/* Retorna la cantidad de filas de la pantalla para caracteres */
int text_rows() {
	return HEIGHT;
}

/* Retorna la cantidad de columnas de la pantalla para caracteres */
int text_cols() {
	return WIDTH;
}

/* Carga las resoluciones de la pantalla */
void load_vDriver(int x, int y) {
	x_res = get_res((unsigned char *)0x0005C12);
	y_res = get_res((unsigned char *)0x0005C14);
}

// Agarra dos bytes que son los correspondientes a la resolucion en VESA.
static int get_res(unsigned char * ptr) {
	unsigned char * res_byte = ptr;
    int res = 0;
    res += *(res_byte+1);
    res = res << 8;
    res += *res_byte;
	return res;
}

/* Retorna 1 si los colores corresponden a una configuracion RGB */
static int valid_colors(uint64_t r, uint64_t g, uint64_t b) {
	return r >= MIN_RGB && r <= MAX_RGB && g >= MIN_RGB
			&& g <= MAX_RGB && b >= MIN_RGB && b <= MAX_RGB;
}

/* Retorna 1 si un pixel es válido, es decir, esta dentro de los limites de la pantalla */
static int valid_pixel(int x, int y) {
	return (x >= 0 && x <= SCREEN_WIDTH && y >= 0 && y <= SCREEN_HEIGHT);
}

/* Pinta de blanco un pixel */
static void fillChar(int x, int y) {
	fill(char_color.red, char_color.green, char_color.blue, x, y); // pinta de blanco
}

/* Pinta de negro un pixel */
static void fillBackground(int x, int y) {
	fill(bg_color.red, bg_color.green, bg_color.blue, x, y); // pinta de negro
}

/* Pinta un pixel de un color recibido por parámetro como RGB */
int fill(char red, char green, char blue, int x, int y) {
	if (!valid_pixel(x, y))
		return 0;

	unsigned char * linearVESABuffer = video_base_ptr();
	unsigned char * VBEAdress = linearVESABuffer + 3 * (x + y * SCREEN_WIDTH);
	VBEAdress[0] = blue;
	VBEAdress[1] = green;
	VBEAdress[2] = red;
	return 1;
}

void graphicLinealFunction(int a, int b) {
  graphicCuadraticFunction(0, a, b);
}

void graphicCuadraticFunction(int a, int b, int c){
  int aux = a + b + c;
  int defaultSpace = 1;
  colorCrossAxis();
  int x;
  int y;
  while(aux > (SCREEN_HEIGHT/2)*defaultSpace) {
    defaultSpace *= 10;
  }
  for(x=0; x < SCREEN_WIDTH ; x++) {
    y = (a*(x^2) + b*x + c)/defaultSpace;
    fill(255, 0, 0, x, y);
  }
}

void colorCrossAxis() {
  int x = SCREEN_WIDTH / 2;
  int y;
  for(y=0; y < SCREEN_HEIGHT; y++) {
    fillChar(x, y);
  }
  y=SCREEN_HEIGHT/2;
  for(x=0; x < SCREEN_WIDTH; x++){
    fillChar(x, y);
  }
}

int checkValue(char * entry) {
	int value = 1;
	char index = 0;
	char c = entry[index];
	while(c!='\0') {
		if(c > '0' && c < '9') {
			value = value*10 + (c -'0');
		} else if(c == '-'){
			if(index == 0) {
				value *= -1;
			} else {
				return 0;
			}
		} else {
			return 0;
		}
		index++;
		c = entry[index];
	}
	return 1;
}
