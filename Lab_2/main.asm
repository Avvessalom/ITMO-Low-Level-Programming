%define buf_size 255

global _start
extern find_word
extern print_string
extern exit
extern read_word

section .data
	word_buf: times buf_size db 0x00
	fail: db "fail", 10, 0
	start: db"write the key --> ", 0
	it_is: db "value = ", 0

%include "./words.inc"

section .text

_start:
	mov rdi, start
	call print_string

	mov rdi, word_buf
	mov rsi, buf_size
	call read_word

	mov rdi, word_buf
	mov rsi,pupa
	call find_word
	test rdi,rdi
	jnz .ok

	mov rdi, fail
	call print_string
	mov rax, 1
	call exit

	.ok:
		push rdi
		mov rdi, it_is
		call print_string
		pop rdi
		call print_string
		mov rax,0
		call exit
