GLOBAL triggerInvalidOpcode
GLOBAL triggerDivideByZeroo
GLOBAL triggerOverflow


section .text
triggerDivideByZeroo:
	int 0h
	ret

triggerOverflow:
	mov rax, 99999999999h
	mov rdx, 99999999999h
	mov ebx, 5
	div ebx
	ret

triggerInvalidOpcode:
	ud2
	ret