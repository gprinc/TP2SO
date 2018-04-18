section .text
global gethours
global getminutes
global getseconds

setnormaltime:
    mov al, 0x0B
    out 70h, al
    in al, 71h
    or al, 0x04
    out 71h, al
    ret


gethours:
    call setnormaltime
    mov al, 4
    out 70h, al
    in al, 71h
    ret

getminutes:
    call setnormaltime
    mov al, 2
    out 70h, al
    in al, 71h
    ret

getseconds:
    call setnormaltime
    mov al, 0
    out 70h, al
    in al, 71h
    ret
