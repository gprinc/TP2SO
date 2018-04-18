#include "system.h"
//Defined in stdio.asm
void printf();
char* scanf();
void paint();

void putChar(char c){
	char printChar[2] = {c, 0};
	printf(printChar);
	return;
}

void printNum(const int num){
	char string[100];
	int aux = num;
	int i = 1;
	int divisor = 1;
	if (aux < 0){
		while(aux /= 10)
			i++;
		aux = -num;
		string[0] = '-';
		for (int j = 1; j < i + 1; j++){
			divisor = 1;
			for (int k = 1; k < i+ 1-j; k++)
				divisor *= 10;
			string[j] = '0' + (int)(aux/divisor);
			aux -= divisor * (int)(aux/divisor);
		}
		string[++i] = 0;
	} else {
		while(aux /= 10)
			i++;
		aux = num;
		for (int j = 0; j < i; j++){
			divisor = 1;
			for (int k = 1; k < i-j; k++)
				divisor *= 10;
			string[j] = '0' + (int)(aux/divisor);
			aux -= divisor * (int)(aux/divisor);
		}

		string[i] = 0;
	}
	
	printf(string);
	return;
}

char getChar(){
	char* keyboardBuffer = scanf();
	int i = 0;
	while(keyboardBuffer[i++] != 0);
	return keyboardBuffer[--i];
}

void paintPixel(int x, int y, int r, int g, int b){
	paint(0, x, y, r, g, b);
	return;
}