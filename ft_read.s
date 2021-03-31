global  _ft_read
extern  ___error
section .text

_ft_read:
	mov     rax, 0x2000003
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