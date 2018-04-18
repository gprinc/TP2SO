GLOBAL getHours
GLOBAL getMinutes
GLOBAL getSeconds

section .text

setnormaltime:
    mov al, 0x0B
    out 70h, al
    in al, 71h
    or al, 0x04
    out 71h, al
    ret

getHours:
    call setnormaltime
    mov al, 4
    out 70h, al
    in al, 71h
    ret

getMinutes:
    call setnormaltime
    mov al, 2
    out 70h, al
    in al, 71h
    ret

getSeconds:
    call setnormaltime
    mov al, 0
    out 70h, al
    in al, 71h
    ret
