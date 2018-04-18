GLOBAL printf
GLOBAL scanf
GLOBAL clearScreen
GLOBAL paint

section .text
printf:
	mov rsi, rdi
	mov rdi, 0x2
	int 80h
	ret

scanf:
	mov rsi, rdi
	mov rdi, 0x1
	int 80h
	ret

clearScreen:
	mov rdi, 0x3
	int 80h
	ret

paint:
	mov rdi, 0x5
	int 80h
	ret