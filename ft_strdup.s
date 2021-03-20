global _ft_strdup

section .text
extern _ft_strlen
extern _malloc
extern _ft_strcpy

_ft_strdup:
	call _ft_strlen
	push rdi
	mov rdi, rax
	inc rdi
	call _malloc
	cmp rax, 0
	je err
	mov rdi, rax
	pop rsi
	call _ft_strcpy

	err:
	    ret
