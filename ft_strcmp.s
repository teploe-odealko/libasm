global _ft_strcmp

section .text
_ft_strcmp:
	xor     rcx, rcx
	xor     rax, rax
	xor     rbx, rbx
compare:	
	cmp     byte [rdi + rcx], 0
	jz      exit
	cmp     byte [rsi + rcx], 0
	jz      exit
	mov     al, [rdi + rcx]
	cmp     [rsi + rcx], al
	jnz     exit
	inc     rcx
	jmp     compare
exit:
	mov     al, [rdi + rcx]
	mov     bl, [rsi + rcx]
	cmp     rax, rbx
	jz      equal
	sub     rax, rbx
	ret
equal:
	mov	rax, 0
	ret