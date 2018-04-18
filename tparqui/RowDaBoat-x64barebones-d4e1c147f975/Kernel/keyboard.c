#include <standardio.h>
#include <naiveConsole.h>
#define BUFFER_SIZE 100

char buffer[BUFFER_SIZE];
char auxBuffer[BUFFER_SIZE];

int bufferLength = 0;

static const char keyCodes[] = {27, '`', '1', '2', '3', '4', '5', '6', '7', '8', '9', '0', '-', '=', '\b', // \b should be 8
								'\t', 'q', 'w', 'e', 'r', 't', 'y', 'u', 'i', 'o', 'p', '{', ']', '\n',
								' ', 'a', 's', 'd', 'f', 'g', 'h', 'j', 'k', 'l', ';', ' ', ' ', '\n',
								' ', 'z', 'x', 'c', 'v', 'b', 'n', 'm', ',', '.', '/', ' ', ' ', ' ', ' '};

void clearBuffer(char* buffer){
	for (int i = 0; i < BUFFER_SIZE; i++)
		buffer[i] = 0;
}
 
void handle_keyboard_input(int input){
	if (auxBuffer[0] != 0)
		clearBuffer(auxBuffer);
	if (input >= 128)
		return;
	if (keyCodes[input] == '\b'){
		bufferLength--;
		if (bufferLength < 0)
			bufferLength = 0;
		buffer[bufferLength] = 0;
		putChar(keyCodes[input]);
		return;
	}
	putChar(keyCodes[input]);
	buffer[bufferLength++] = keyCodes[input];
	buffer[bufferLength] = 0;
}

// char* getKeyboardBuffer(){
// 	for (int i = 0; i < bufferLength; i++){
// 		auxBuffer[i] = buffer[i];
// 	}
// 	if (buffer[bufferLength-1] == '\n'){
// 		bufferLength = 0;
// 		clearBuffer(buffer);
// 	}
// 	//Null terminate auxBuffer
// 	return auxBuffer;
// }

void getKeyboardBuffer(char* target){
	for (int i = 0; i <= bufferLength; i++){
		target[i] = buffer[i];
	}
	if (buffer[bufferLength-1] == '\n'){
		bufferLength = 0;
		clearBuffer(buffer);
	}
	return;
}

int getKeyboardBufferLength(){
	return bufferLength;
}