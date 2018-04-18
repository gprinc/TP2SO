GLOBAL malloc
GLOBAL getScreenWidth
GLOBAL getScreenHeight

malloc:
	mov rsi, rdi
	mov rdi, 0x1
	int 80h
	ret

getScreenWidth:
	mov rdi, 0x6
	mov rsi, 0x0
	int 80h
	ret

getScreenHeight:
	mov rdi, 0x6
	mov rsi, 0x1
	int 80h
	ret