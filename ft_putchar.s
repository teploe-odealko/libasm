global _ft_putchar

;.section data


section .text
_ft_putchar:
	push	rsi
	mov	rsi, rdi
	mov	rdi, 1
	mov	rdx, 3
	mov	rax, 0x02000004
	syscall
	pop	rsi
	ret
