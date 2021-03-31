global  _ft_write
extern  ___error
section .text

_ft_write:
	mov     rax, 0x2000004
	syscall
    jc      error
	ret
error:
    mov     r12, rax
    push    rbx
    call    ___error
    pop     rbx
    mov     [rax], r12
    mov     rax, -1
    ret