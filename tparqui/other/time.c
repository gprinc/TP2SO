#include "time.h"

static uint8_t * const video = (uint8_t*)0xB8000;
static uint8_t * currentVideo = (uint8_t*)0xB8000;

int gethours();
int getMinutes();
int getSeconds();

void callAsmPrintTime(){
  int hours = gethours();
  int minutes = getMinutes();
  int seconds = getSeconds();

  printTime(hours, minutes, seconds);
}

void printTime(int h, int m, int s) {
  char u;
  char d;
  u = h / 10 + '0';
  d = h % 10 + '0';
  printChars(u,d,':');
  u = m / 10 + '0';
  d = m % 10 + '0';
  printChars(u,d,':');
  u = s / 10 + '0';
  d = s % 10 + '0';
  printChars(u,d,' ');
}

void printChars(char u, char d, char t){
  *currentVideo = u;
  currentVideo += 2;
  *currentVideo = d;
  currentVideo += 2;
  *currentVideo  = t;
  currentVideo += 2;
}
