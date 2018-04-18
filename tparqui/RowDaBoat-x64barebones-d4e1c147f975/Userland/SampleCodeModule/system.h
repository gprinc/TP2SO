//Defined in system.asm

void* malloc(int bytes);
int getScreenWidth();
int getScreenHeight();

//Defined in exceptionTriggers.asm
void triggerDivideByZeroo();
void triggerOverflow();
void triggerInvalidOpcode();

void printTime();