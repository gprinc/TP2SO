GLOBAL getModeInfo
section .text
getModeInfo:
	mov rax, 0x4F01
	mov rcx, 0x0
	int 10h
	mov rax, 0x0
	mov rax, rcx
	ret