#include <standardio.h>

//Defined in asm/intelUtils.asm
int get_reg_rax();
int get_reg_rbx();
int get_reg_rcx();
int get_reg_rdx();
int get_reg_rbp();
int get_reg_rdi();
int get_reg_rsi();
int get_reg_r8();
int get_reg_r9();
int get_reg_r10();
int get_reg_r11();
int get_reg_r12();
int get_reg_r13();
int get_reg_r14();
int get_reg_r15();

void printCPUState(){
	printf("RAX: ");
	printNum(get_reg_rax());
	printf(" - ");
	printf("RBX: ");
	printNum(get_reg_rbx());
	printf(" - ");
	printf("RCX: ");
	printNum(get_reg_rcx());
	printf(" - ");
	printf("RDX: ");
	printNum(get_reg_rdx());
	printf(" - ");
	printf("RBP: ");
	printNum(get_reg_rbp());
	printf("\n");
	printf("RDI: ");
	printNum(get_reg_rdi());
	printf(" - ");
	printf("RSI: ");
	printNum(get_reg_rsi());
	printf(" - ");
	printf("R8: ");
	printNum(get_reg_r8());
	printf(" - ");
	printf("R9: ");
	printNum(get_reg_r9());
	printf("\n");
	printf("R10: ");
	printNum(get_reg_r10());
	printf(" - ");
	printf("R11: ");
	printNum(get_reg_r11());
	printf(" - ");
	printf("R12: ");
	printNum(get_reg_r12());
	printf(" - ");
	printf("R13: ");
	printNum(get_reg_r13());
	printf("\n");
	printf("R14: ");
	printNum(get_reg_r14());
	printf(" - ");
	printf("R15: ");
	printNum(get_reg_r15());
	printf("\n");
}

//Access Denied exception handler
void handle_exc_access_denied(){
	
}

//Zero Division exception handler
void handle_exc_divide_by_0(){
	printf("[EXCEPTION 00] Division by zero exception!\nThe program will be terminated.\nThe register values were the following when the interruption took place:\n");
	printCPUState();
	printf("-------------------------------\n");
}

//Overflow exception handler
void handle_exc_overflow(){
	printf("[EXCEPTION 04] Overflow exception!\nThe program will be terminated.\nThe register values were the following when the interruption took place:\n");
	printCPUState();
	printf("-------------------------------\n");
}

//Invalid Operation Code exception handler
void handle_exc_invalid_opcode(){
	printf("[EXCEPTION 06] Invalid Operation Code exception!\nThe program will be terminated.\nThe register values were the following when the interruption took place:\n");
	printCPUState();
	printf("-------------------------------\n");
}

//Timer Tick exception handler
void handle_exc_timer_tick(){
	static int ticks = 0;
	ticks++;
}

