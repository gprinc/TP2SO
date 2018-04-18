#include <naiveConsole.h>
#include <videoDriver.h>

uint16_t width;
uint16_t height;
uint8_t* videoBasePtr;

uint8_t getModeInfo();

typedef struct __attribute__((packed)) ModeInfoBlock {
  uint16_t attributes;
  uint8_t winA,winB;
  uint16_t granularity;
  uint16_t winsize;
  uint16_t segmentA, segmentB;
  uint32_t FARWindowPositioning;
  uint16_t pitch; // bytes per scanline
 
  uint16_t Xres, Yres;
  uint8_t Wchar, Ychar, planes, bpp, banks;
  uint8_t memory_model, bank_size, image_pages;
  uint8_t reserved0;
 
  uint8_t red_mask, red_position;
  uint8_t green_mask, green_position;
  uint8_t blue_mask, blue_position;
  uint8_t rsv_mask, rsv_position;
  uint8_t directcolor_attributes;
 
  uint32_t physbase;  // your LFB (Linear Framebuffer) address ;)
  uint32_t reserved1;
  uint16_t reserved2;
} ModeInfoBlock_t;

void initVideoDriver(){
	ModeInfoBlock_t* infoBlock = (ModeInfoBlock_t*) 0x5C00;
	videoBasePtr = (uint8_t*) infoBlock->physbase;
	width = infoBlock->Xres;
	height = infoBlock->Yres;
	fillScreen(0, 0, 0);
}

int getScreenWidth(){
	return (int)width;
}

int getScreenHeight(){
	return (int)height;
}

uint8_t* getVideoBasePtr(){
	ModeInfoBlock_t* infoBlock = (ModeInfoBlock_t*) 0x5C00;
	return (uint8_t*) infoBlock->physbase;
}

void paintPixel(int x, int y, int r, int g, int b){
	if (x > width || y > height || x < 0 || y < 0)
		return;

	uint8_t * currentVideo = videoBasePtr;

	currentVideo += 3 * (x + y * width);// CHAGNED
	*currentVideo = b;
	currentVideo++;
	*currentVideo = g;
	currentVideo++;
	*currentVideo = r;
}

int getPixelRed(int x, int y){
	return *(videoBasePtr + 3 * (x + y * width) + 2); 
}

int getPixelGreen(int x, int y){
	return *(videoBasePtr + 3 * (x + y * width) + 1);
}

int getPixelBlue(int x, int y){
	return *(videoBasePtr + 3 * (x + y * width));
}

void fillScreen(int r, int g, int b){
	uint8_t * currentVideo = videoBasePtr;
	for (int i = 0; i < width * 3 * height ; i++){
		int num = (long int)currentVideo % 3;
		switch(num){
			case 0:
				*currentVideo = b;
				break;
			case 1:
				*currentVideo = g;
				break;
			case 2:
				*currentVideo = r;
				break;
		}
		currentVideo++;
	}
}

//Scrolls the screen upwards by x pixels
void scrollScreen(int x){

	for (int j = x; j < height; j++)
		for (int i = 0; i < width; i++)
			paintPixel(i, j-x, getPixelRed(i, j), getPixelGreen(i, j), getPixelBlue(i, j));

	for (int j = height - x; j < height; j++)
		for (int i = 0; i < width; i++)
			paintPixel(i, j, 0, 0, 0);
}

