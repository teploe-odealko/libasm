global	_ft_strcpy

section	.text
_ft_strcpy:
	xor     rdx, rdx
	xor		rax, rax

copy:
	mov		al, [rsi + rdx]
	mov		[rdi + rdx], al
	cmp		BYTE[rsi + rdx], 0
	jz		end
	inc		rdx
	jmp		copy

end:
	mov     rax, rdi
	ret
