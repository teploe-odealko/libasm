global _ft_strcmp

section .text
_ft_strcmp:
	xor	rcx, rcx
	xor	al, al
compare:	
	cmp	byte [rdi + rcx], 0
	jz exit
	cmp	byte [rsi + rcx], 0
	jz exit
	mov	al, [rdi + rcx]
	cmp	[rsi + rcx], al
	jnz	exit
	inc	rcx
	jmp	compare
exit:
	mov	al, [rdi + rcx]
	cmp	[rsi + rcx], al
	jz	equal
	sub	al, [rsi + rcx]
	movsx	rax, al
	ret	
equal:
	mov	rax, 0
	ret
