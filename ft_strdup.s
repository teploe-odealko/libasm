global  _ft_strdup
extern  _ft_strlen
extern  _malloc
extern  _ft_strcpy
extern  ___error

section .text
_ft_strdup:
	call    _ft_strlen
	push    rdi
	mov     rdi, rax
	inc     rdi
	call    _malloc
	cmp     rax, 0
	jz      error
	mov     rdi, rax
	pop     rsi
	call    _ft_strcpy

error:
    ret