GLOBAL getSystemSeconds
GLOBAL getSystemMinutes
GLOBAL getSystemHours
GLOBAL malloc

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

malloc:
	mov rsi, rdi
	mov rdi, 0x1
	int 80h
	ret