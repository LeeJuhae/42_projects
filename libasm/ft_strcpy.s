section .text
	global _ft_strcpy

_ft_strcpy:
	mov rax, 0
	loop:
		cmp BYTE [rsi + rax], 0
		je end
		mov dl, BYTE [rsi + rax]
		mov BYTE [rdi + rax], dl
		inc rax
		jmp loop
	end:
		mov BYTE [rdi + rax], 0
		mov rax, rdi
		ret
