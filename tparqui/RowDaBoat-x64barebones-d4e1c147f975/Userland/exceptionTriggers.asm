GLOBAL triggerDivideByZero
GLOBAL triggerOverflow
GLOBAL triggerInvalidOpcode

section .text

triggerDivideByZero:
	mov rax, 42
	mov rdx, 0
	mov ebx, 0
	div ebx
	ret

triggerOverflow:
	
	ret
	

triggerInvalidOpcode:

	ret