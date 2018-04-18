GLOBAL get_reg_rax
GLOBAL get_reg_rbx
GLOBAL get_reg_rcx
GLOBAL get_reg_rdx
GLOBAL get_reg_rbp
GLOBAL get_reg_rdi
GLOBAL get_reg_rsi
GLOBAL get_reg_r8
GLOBAL get_reg_r9
GLOBAL get_reg_r10
GLOBAL get_reg_r11
GLOBAL get_reg_r12
GLOBAL get_reg_r13
GLOBAL get_reg_r14
GLOBAL get_reg_r15

section .text
get_reg_rax:
	ret
get_reg_rbx:
	mov rax, rbx
	ret
get_reg_rcx:
	mov rax, rcx
	ret
get_reg_rdx:
	mov rax, rdx
	ret
get_reg_rbp:
	mov rax, rbp
	ret
get_reg_rdi:
	mov rax, rdi
	ret
get_reg_rsi:
	mov rax, rsi
	ret
get_reg_r8:
	mov rax, r8
	ret
get_reg_r9:
	mov rax, r9
	ret
get_reg_r10:
	mov rax, r10
	ret
get_reg_r11:
	mov rax, r11
	ret
get_reg_r12:
	mov rax, r12
	ret
get_reg_r13:
	mov rax, r13
	ret
get_reg_r14:
	mov rax, r14
	ret
get_reg_r15:
	mov rax, r15
	ret