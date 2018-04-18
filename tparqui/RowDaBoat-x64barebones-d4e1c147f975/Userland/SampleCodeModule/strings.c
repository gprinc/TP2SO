#include "math.h"
#include "standardio.h"
//String compare
int strCmp(char* a, char* b){
	int i = 0;
	while(a[i] != 0 || b[i] != 0){
		if (a[i] > b[i])
			return 1;
		else if (a[i] < b[i])
			return -1;
		i++;
	}
	return 0;
}

//Checks if string a is cntained within string b
int strContains(const char* a, const char* b){
	int i = 0, j = 0;
	while (a[i] != b[j]){
		j++;
		if (b[j] == 0)
			return 0;
	}
	while(a[i] != 0){
		if (b[j] == 0)
			return 0;
		if (a[i] != b[j])
			return strContains(a, b+i);
		i++;
		j++;
	}
	return 1;
}

int parseInt(char* string){
	int numDigits = 0, negative = 0;
	int result = 0;

	if (string[0] == '-')
		negative = 1;

	numDigits = negative?1:0;
	while(string[numDigits] != 0){
		if (string[numDigits] < '0' || string[numDigits] > '9'){
			return 0;
		}
		numDigits++;
	}
	if (negative) numDigits--;

	for(int i = negative?numDigits:numDigits-1; i >= negative?1:0; i--){
		result += (string[i] - '0') * pow(10, negative?numDigits-i:numDigits-1-i);
	}
	printNum(result);
	return negative? (-1) * result : result;

}