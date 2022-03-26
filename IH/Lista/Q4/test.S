	.globl test
test:

	mov X9, X0                     ;move o numero a ser invertido para o registrador X9

	b not                          ;Faz a operacao not no regitrador X9
	endnot:                        ;Endereco de retorno da operacao not

	mov X0, X9                     ;Move o regitrador X9 ja invertido para o registrador de retorno

return:
	br	X30

not:
	mov X10, 0xffffffffffffffff    ;seta todos os bits do registrador X10 para 1
	eor X9,X10,X9                  ;fazendo a operacao bit a bit com o valor entre X10 e X9
							       ;como todos os bits do regitrador X10 sao 1, se o bit do registrador X9
								   ;for 1: 1 xor 1 = 0, e se o bit do regitrador X9 for 0:
								   ; 1 xor 0 = 1, logo cada bit sera invertido, configurando uma operacao bit a bit NOT X11
	b endnot
	
	 
