#include <naiveConsole.h>
#include <videoDriver.h>
#include <font.h>

static uint32_t uintToBase(uint64_t value, char * buffer, uint32_t base);

static char buffer[64] = { '0' };
static const uint32_t columns = 79;
static const uint32_t rows = 29 ;

int currentRow = 0;
int currentCol = 0;

void ncReturn(){
	currentCol--;
	if (currentCol < 0){
		currentCol = 0;
	} else{
		ncPrintChar(' ');
		currentCol--;
	}	
	return;
}

void ncNewline()
{
	currentRow++;
	currentCol = 0;
	if (currentRow > rows){
		currentRow--;
		scrollScreen(CHAR_HEIGHT);
	}
	return;
}

void ncPrintChar(const char character)
{
	if (character == '\n'){
		ncNewline();
		return;
	} else if (character == '\b'){
		ncReturn();
		return;
	} else {
		for (int i = 0; i < CHAR_HEIGHT; i++)
			for (int j = 0; j < CHAR_WIDTH; j++)
				paintPixel(currentCol * CHAR_WIDTH + j, currentRow * CHAR_HEIGHT + i, 0, 0, 0);

		unsigned char * pixelMap = pixel_map(character);
		for (int i = 0; i < CHAR_HEIGHT; i++){
			char current = pixelMap[i];
			char mask[] = {128, 64, 32, 16, 8, 4, 2, 1};
			for (int j = 0; j < CHAR_WIDTH; j++){
				char aux = mask[j] & current;
				if (aux != 0)
					paintPixel(currentCol * CHAR_WIDTH + j, currentRow * CHAR_HEIGHT + i, 255, 255, 255);
			}
		}
	}

	currentCol++;
	if (currentCol > columns){
		ncNewline();
	}	
	return;
}

void ncPrint(const char * string)
{
	int i;

	for (i = 0; string[i] != 0; i++)
		ncPrintChar(string[i]);
	return;
}

void ncPrintDec(uint64_t value)
{
	ncPrintBase(value, 10);
}

void ncPrintHex(uint64_t value)
{
	ncPrintBase(value, 16);
}

void ncPrintBin(uint64_t value)
{
	ncPrintBase(value, 2);
}

void ncPrintBase(uint64_t value, uint32_t base)
{
    uintToBase(value, buffer, base);
    ncPrint(buffer);
}

void ncClear()
{
	currentRow = 0;
	currentCol = 0;
	fillScreen(0, 0, 0);
	return;
}

static uint32_t uintToBase(uint64_t value, char * buffer, uint32_t base)
{
	char *p = buffer;
	char *p1, *p2;
	uint32_t digits = 0;

	//Calculate characters for each digit
	do
	{
		uint32_t remainder = value % base;
		*p++ = (remainder < 10) ? remainder + '0' : remainder + 'A' - 10;
		digits++;
	}
	while (value /= base);

	// Terminate string in buffer.
	*p = 0;

	//Reverse string in buffer.
	p1 = buffer;
	p2 = p - 1;
	while (p1 < p2)
	{
		char tmp = *p1;
		*p1 = *p2;
		*p2 = tmp;
		p1++;
		p2--;
	}

	return digits;
}

void moveCharsUp(){
	scrollScreen(CHAR_HEIGHT);
}
