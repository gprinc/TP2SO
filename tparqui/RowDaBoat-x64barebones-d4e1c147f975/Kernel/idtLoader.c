/*
* IDT.c
*/
#include <stdint.h>
#include <defs.h>
#include <interruptions.h>
#include <exceptions.h>

#pragma pack(push)
#pragma pack (1)

typedef struct {
	uint16_t offset_l;
	uint16_t selector;
	uint8_t cero;
	uint8_t access;
	uint16_t offset_m;
	uint32_t offset_h;
	uint32_t other_cero;
} INT_DESCR;

#pragma pack(pop)

INT_DESCR * idt = (INT_DESCR *) 0;

void setup_IDT_entry (int index, uint64_t offset) {
	idt[index].offset_l = offset & 0xFFFF;
	idt[index].selector = 0x08;
	idt[index].cero = 0;
	idt[index].access = ACS_INT;
	idt[index].offset_m = (offset >> 16) & 0xFFFF;
	idt[index].offset_h = (offset >> 32) & 0xFFFFFFFF;
	idt[index].other_cero = 0;
}

//Defined in asm/interruptions.asm
void exc_divide_by_0();
void exc_overflow();
void exc_invalid_opcode();
void exc_timer_tick();

void int_syscall();
void int_keyboard();

void _cli();
void _sti();
void picMasterMask();
void picSlaveMask();

void initIDT(){
	_cli();

	//Divide by 0 exception 
	setup_IDT_entry(0x0, (uint64_t)&exc_divide_by_0);

	//Overflow exception 
	setup_IDT_entry(0x4, (uint64_t)&exc_overflow);

	//Invalid Operation Code exception
	setup_IDT_entry(0x6, (uint64_t)&exc_invalid_opcode);


	//Access Denied exception(cooler name for SegFault)

	//Timer tick exception
	setup_IDT_entry(0x20, (uint64_t)&exc_timer_tick);

	//Keyboard interruption
	setup_IDT_entry(0x21, (uint64_t)&int_keyboard);

	//Syscalls interruption
	setup_IDT_entry(0x80, (uint64_t)&int_syscall);

	picMasterMask(0xFC); //11111100
	picSlaveMask(0xFF);
	_sti();
}