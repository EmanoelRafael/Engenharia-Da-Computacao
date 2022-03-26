	.globl test
test:

	mov X9, X0                   ;Carrega o endereco inicial da string em X9
	mov X11, 0                   ;Zera X11 que vai ser o contador
	mov X12, 0                   ;Zera X12 que vai ser a quantidade de vogais da frase
	
	loop:
		ldurb W10, [X9,X11]      ;Carrega o proximo caractere da string
		add X11, X11, 1          ;Incrementa o contador
		cmp W10, #0           
		b.eq return              ;Se chegou no fim da string, retorna

		;Faz as comparações
		cmp W10, #97
		b.eq vogal
		cmp W10, #101
		b.eq vogal
		cmp W10, #105
		b.eq vogal
		cmp W10, #111
		b.eq vogal
		cmp W10, #117
		b.eq vogal

		b loop                   ;Se o caractere nao for vogal, repete o loop
		vogal:
			addi X12, X12, 1     ;Se o caractere for vogal, incrementa X12
			b loop               ;Repete o loop
		
	
return:
	mov X0, X12                  ;Move a quantidade de vogais (em X12) para o registrador de retorno
	br	X30
