GLOBAL printf
GLOBAL scanf
GLOBAL clearScreen
GLOBAL paint

GLOBAL getSystemSeconds
GLOBAL getSystemMinutes
GLOBAL getSystemHours

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

getSystemSeconds:
	mov rdi, 0x4 ;Time syscall
	mov rsi, 0x0 ;Specify seconds
	int 80h
	ret

getSystemMinutes:
	mov rdi, 0x4
	mov rsi, 0x1
	int 80h
	ret
	
getSystemHours:
	mov rdi, 0x4
	mov rsi, 0x2
	int 80h
	ret