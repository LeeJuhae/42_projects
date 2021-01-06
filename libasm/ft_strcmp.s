section .text
	global _ft_strcmp

_ft_strcmp:
	mov rcx, 0
	loop:
		mov al, BYTE [rdi + rcx]
		cmp al, 0
		je end
		cmp al, BYTE [rsi + rcx]
		jne end
		inc rcx
		jmp loop
	equal:
		mov rax, 0
		ret
	greater:
		mov rax, 1
		ret
	less:
		mov rax, -1
		ret
	end:
		cmp al, BYTE [rsi + rcx]
		je equal
		ja greater
		jb less
