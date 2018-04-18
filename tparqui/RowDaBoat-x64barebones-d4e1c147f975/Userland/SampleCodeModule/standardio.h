//Defined in standardio.asm
void printf(char * string);
int scanf(char* target);
void clearScreen();

//Defined in standardio.c
void putChar(char c);
void printNum(const int n);
char getChar();
void paintPixel();

int getSystemSeconds();
int getSystemMinutes();
int getSystemHours();