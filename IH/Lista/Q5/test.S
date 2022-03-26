	.globl test
test:

	mov X12, X0                ;X12 é a variavel de condicao
	mov X13, X1                ;X13 é um parametro (contador do loop)
	mov X9, 0                  ;X9 é uma variavel auxiliar
	          
	b rpt                      ;Chama a pseudo instrucao rpt
	endrpt:                    ;Endereco de retorno da instrucao rpt

	mov X0, X9                 ;Move a variavel auxiliar para o registrador de retorno

return:
	br	X30

rpt:
	cmp X12,0           
	b.le endrpt               ;Se o valor do registrador X12 <= 0 a condicao nao é satisfeita e a instrucao acaba
	sub X12,X12,1             ;Do contrario X12 > 0, e a instrucao faz X12 = X12 - 1
	b loop                    

;loop de exemplo
loop:                
	cmp X13, 0       
	b.le endrpt               ;Se X13 < 0 o loop acaba
	sub X13, X13, 1           ;decrementa o contador X13
	;Codigo do loop
	add X9, X9, 1             ;incrementa a variavel X9
	b loop                    ;Repete o loop
