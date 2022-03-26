	.globl test
test:

	mov X12,X0                        ;move o primeiro parametro para o registrador X12
	mov X13,X1                        ;move o segundo parametro para o registrador X13

	;registradores com valores uteis
	mov X15,0xffffffffff000fff        ;usado para zerar os bits 23 - 22 de algum registrador com a operacao and (1 and 0 = 0 e 0 and 0 = 0)
	mov X9,0x0000000000fff000         ;usado para extrair os bits 23 - 22 de algum registrador com a operacao and (1 and 1 = 1 e 0 and 1 = 0)
	mov X10,0xff000fffffffffff        ;usado para zerar os bits 55 - 44 de algum registrador com a operacao and

	and X11,X9,X12                    ;obtem os bits de 23 - 12 do registrador X12 e coloca no registrador X11
	and X12,X15,X12                   ;zera os bits de 23 - 12 do registrador X12
	lsl X11,X11,32                    ;move os bits das posicoes 23 - 12 para as posicoes 55 - 44 no registrador X11
	and X14,X10,X13                   ;zera os bits das posicoes 55 - 44 do registrador X13
	orr X13,X14,X11                   ;adiciona os bits do registrador X11 nas posicoes 55 - 44 do registrador X13

	mov X0, X13                       ;move o valor de X13 para o registrador de retorno X0

return:
	br	X30
