EXTERN handle_syscall
EXTERN handle_keyboard_input
EXTERN handle_exc_divide_by_0
EXTERN handle_exc_overflow
EXTERN handle_exc_invalid_opcode
EXTERN handle_exc_timer_tick
EXTERN printNum

GLOBAL int_keyboard
GLOBAL int_syscall
GLOBAL exc_divide_by_0
GLOBAL exc_overflow
GLOBAL exc_invalid_opcode
GLOBAL exc_timer_tick
GLOBAL _cli
GLOBAL _sti
GLOBAL picMasterMask
GLOBAL picSlaveMask

section .text

%macro eraseState 0
	mov rax, 0x1
	mov rbx, 0x1
	mov rcx, 0x1
	mov rdx, 0x0
	mov rdi, 0x1
	mov rsi, 0x1
	mov r8, 0x1
	mov r9, 0x1
	mov r10, 0x1
	mov r11, 0x1
	mov r12, 0x1
	mov r13, 0x1
	mov r14, 0x1
	mov r15, 0x1
%endmacro

%macro pushState 0
	push rax
	push rbx
	push rcx
	push rdx
	push rbp
	push rdi
	push rsi
	push r8
	push r9
	push r10
	push r11
	push r12
	push r13
	push r14
	push r15
%endmacro

%macro popState 0
	pop r15
	pop r14
	pop r13
	pop r12
	pop r11
	pop r10
	pop r9
	pop r8
	pop rsi
	pop rdi
	pop rbp
	pop rdx
	pop rcx
	pop rbx
	pop rax
%endmacro

%macro pushStateWithoutRAX 0
	push rbx
	push rcx
	push rdx
	push rbp
	push rdi
	push rsi
	push r8
	push r9
	push r10
	push r11
	push r12
	push r13
	push r14
	push r15
	push rsp
%endmacro

%macro popStateWithoutRAX 0
	pop rsp
	pop r15
	pop r14
	pop r13
	pop r12
	pop r11
	pop r10
	pop r9
	pop r8
	pop rsi
	pop rdi
	pop rbp
	pop rdx
	pop rcx
	pop rbx
%endmacro


int_syscall:
	pushStateWithoutRAX

	call handle_syscall

	popStateWithoutRAX
	iretq

int_keyboard:
	pushState

	mov rax, 0x0
	mov rdi, 0x0
	in al, 60h
	movzx rdi, al
	call handle_keyboard_input

	mov al, 20h
	out 20h, al

	popState
	iretq


exc_divide_by_0:

	call handle_exc_divide_by_0


	pop rbp
	mov rbp, 0x400000
	push rbp
	
	iretq

exc_overflow:
	pushState

	call handle_exc_overflow

	popState
	iretq

exc_invalid_opcode:

	call handle_exc_invalid_opcode

	pop rbp
	mov rbp, 0x400000
	push rbp

	iretq

exc_timer_tick:
	pushState

	call handle_exc_timer_tick

	mov al, 20h
	out 20h, al

	popState
	iretq

_cli:
	cli
	ret

_sti:
	sti
	ret

picMasterMask:
	push rbp
    mov rbp, rsp
    mov ax, di
    out	21h,al
    pop rbp
    retn

picSlaveMask:
	push    rbp
    mov     rbp, rsp
    mov     ax, di  ; ax = mascara de 16 bits
    out	0A1h,al
    pop     rbp
    retn

section .data
a db "INT 21h lauched BIATCH"