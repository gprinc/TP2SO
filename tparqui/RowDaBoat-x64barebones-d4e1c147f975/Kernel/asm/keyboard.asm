GLOBAL getKeyboardStatus
GLOBAL getKeyboardData

section .text
getKeyboardStatus:
in al, 64h
and rax, 0x1
ret

getKeyboardData:
mov rax, 0x0
in al, 60h
ret
