section .text

GLOBAL exit
GLOBAL string_length
GLOBAL print_string
GLOBAL print_newline
GLOBAL print_char
GLOBAL print_int
GLOBAL print_uint
GLOBAL string_equals
GLOBAL read_char
GLOBAL read_word
GLOBAL parse_uint
GLOBAL parse_int
GLOBAL string_copy


exit:
	xor rax,rax ; обнуляем аккумулятор
	mov rax,60 ; кладм код выхода
	xor rdi,rdi ; обнуляем дата регистр
	syscall ; уходим

string_length:
	xor rax, rax ; обнуляем аккумулятор
	.counter:
		cmp byte[rdi+rax],0 ; считаем адрес и сравнивем с нулём. также ставим флаги
		je .end ; если флаг равен нулю, то выходим из цикла
		inc rax ; если не равен, то учитываем символ инкриментируя аккумулятор
		jmp .counter ; цикл
	.end:
		ret

print_string:
	call string_length ; в rax кладём длинну строки
	mov rsi,rdi ; кладём количество выводимых символов
	mov rdx,rax ; кладём ссылку откуда выводить
	mov rax,1 ; sys_write
	mov rdi,1 ; stdout
	syscall
	xor rax,rax ; убираем за собой
	ret

print_char:
	push rdi ; пихаем символ на стек
	mov rsi,rsp ; адрес вершины стека
	mov rdi,1 ; stdout
	mov rdx,1 ; сколько выводить 
	mov rax,1 ; sys_write
	syscall
	pop rdi ;берем со стека
	ret

print_newline:
	mov rdi,10 ; код новой строки
	jmp print_char

print_uint:
	push r12
	push r13
	mov r12,rsp ; вершину стека в r12
	mov r13,10 ; система счисления "10"
	mov rax,rdi ; полученное число в rax
	dec rsp ; двигаем указатель стека
	mov byte[rsp],0 ; 
	.loop:
		dec rsp ; двигаем указатель стека
		xor rdx,rdx ; обнуляем rdx
		div r13 ; делим на систему счисления
		add rdx,0x30 ; остаток переводим ASCII
		mov byte[rsp],dl ; кладём на стек
		test rax,rax ; ставим флаги по rax
		jz .print ; если ZF=0, в конец
		jmp .loop ;
	.print:
		mov rdi,rsp ; аргумент для принт стринг
		call print_string ;
		mov rsp,r12 ;
	pop r13 ;
	pop r12 ;
	ret

print_int:
	xor rax,rax ; чистим аккумулятор
	mov rax,rdi ; сохраняем полученное число в rax 
	test rax,rax ; ставим флаги
	jns .pos ; если число положительное идём в конец
	mov rdi,'-' ; кладём минус для принт чар
	push rax
	call print_char ; выводим минус
	pop rax ;
	neg rax ; делаем число положительным
	mov rdi,rax ;
	.pos: 
		call print_uint ; выводим число
		ret
		
string_equals:
	call string_length 
	mov rcx,rax ; кладём длинну строки в rcx
	xchg rdi, rsi ; помещаем в rdi адрес второй строки
	call string_length
	cmp rax,rcx ; сравнениваем длины и ставим флаги по итогу
	jne .not_equals ; если не равны (флаг не ноль)
	repe cmpsb ; repe повторять пока равны, cmpsb устанавливаем флаги
	jne .not_equals ; если перебор прекратился, флаг ZF ставится
	mov rax,1 ; возвращаем 1
	ret
	.not_equals:
		mov rax,0 ; возвращаем 0
		ret	

read_char:
	dec rsp ; место для записи символа
	mov rax,0 ; код sys_read
	mov rdi,0 ; откуда читаем
	mov rsi,rsp ; куда кладём
	mov rdx,1 ; сколько читаем
	syscall 
	mov rax, [rsp] ; кладём символ в rax
	inc rsp ; возвращаем указатель стека
	ret

read_word:
	push rbx ; сохраняем значение rbx
    	mov r8, rsi ; сохраняем размер
    	mov r9, rdi ; сохраняем адрес
    	xor r10, r10 ; обнуляй
    	push rdi ; эр ди ай
    	xor rdi, rdi ; мне надоело это коментить
    	mov rdx, 1 ; читаем по байтику
    	.next:
    		inc r10 ;
        	xor rax, rax ;
        	mov rsi, r9 ;
        	syscall
    		cmp r10, r8 ;
    		je .end ;
        	cmp byte [r9], 0xca ;
        	je .end ;
        	cmp byte [r9], 0x21 ;
        	jb .next ;
    	.again:
        	dec r8
        	cmp r8, 1
        	je .overflow
        	inc r9
        	xor rax, rax
        	mov rsi, r9
        	syscall
        	cmp byte [r9], 0x21
        	jb .end
        	cmp byte [r9], 0xca
        	je .end
        	jmp .again
    	.end:
        	mov byte [r9], 0
        	pop rax
       		mov rdx, r9
        	sub rdx, rax
        	pop rbx
        	ret
    	.overflow:
        	pop rax
        	mov rax, 0
        	mov rdx, 0
        	pop rbx
        	ret
			
parse_uint:
	call string_length ; пасхалка. если нашёл, то ты молодец
	mov rcx,rax ;	     если ты препод который это нашёл, то вы тоже молодец :)
	mov rsi,rdi ;	     не валите меня, пожалуйста
	xor rdx,rdx ; 
	xor rax,rax ;
	.pars: 
		xor rdi,rdi ;
		mov dil,byte[rsi+rdx] ;
		cmp dil,'0' ;
		jb .end ;
		cmp dil,'9' ;
		ja .end ;
		sub dil,'0' ;
		imul rax,10 ;
		add rax,rdi ;
		inc rdx ;
		dec rcx ;
		jnz .pars ;
	.end:
		ret

parse_int:
	cmp byte[rdi],'-' ; проверяем на отрицательность чиал, ставим флаги
	je .minus ; если число отрицательное, то обрабатываем его
	jmp parse_uint ; если нет, то обрабатываем как обчную строку
	.minus:
		inc rdi ; пропускаем минус перед числом
		call parse_uint ; обрабатываем как обычную строку
		test rdx,rdx ; ставим флаги
		jz .null ; если после минуса нет числа, то заканчиваем
		neg rax ; инвертируем число
		inc rdx ; учитываем минус
		ret
	.null:
		xor rax,rax ; убираем за собой
		ret
		
string_copy:
	xor rax, rax ;
	xor r9, r9 ;
	xor rcx, rcx ;
    	call string_length ;
    	push rax ;
    	push rsi ;
	.loop:
    		cmp rcx, rdx ; сравниваем счетчик и количество символов
		je .error ; если все копировали, то уходим
    		mov r8, [rdi+rcx] ; в r8 кладём нынешний символ
    		mov [rsi+rcx], r8 ; копируем
    		cmp rax, 0 ;
    		je .end ;
    		dec rax ;
    		inc rcx ; увеличиваем счётчик
    		jmp .loop ;
	.end
		pop rsi ;
		pop rax ;
    		mov byte [rsi+rax], 0 ;
    		ret
	.error:
    		pop rsi ;
		pop rax ;
		mov rax, 0 ;
		ret
