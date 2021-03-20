global	_ft_strcpy

section	.text
_ft_strcpy:
	xor	rdx, rdx
	mov		rax, rdi

copy:
	mov		al, BYTE[rsi + rdx]
	mov		BYTE[rdi + rdx], al
	cmp		BYTE[rsi + rdx], 0
	jz		end
	inc		rdx
	jmp		copy

end:
	mov		BYTE[rdi + rdx], 0
	ret
