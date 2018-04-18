#include "system.h"
void printTime() {
    int h = getSystemHours();
    int m = getSystemMinutes();
    int s = getSystemSeconds();
    putChar(0);

    char timeString[10] = {
        h / 10 + '0',
        h % 10 + '0',
        ':',
        m / 10 + '0',
        m % 10 + '0',
        ':',
        s / 10 + '0',
        s % 10 + '0',
        '\n',
        0
    };
    printf("Current time:\n");
    printf(timeString);
    return;
}