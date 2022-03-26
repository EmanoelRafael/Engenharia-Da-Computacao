	.globl test
test:

	mov X9, X0                            ;X9 recebe o endereco do conjunto de letras
	mov X10, X1                           ;X10 recebe o endereco da palavra
	mov X12, 0    
	mov X14, 0
	mov X16, 0
	mov X17, 0                            ;X17 = quantidade de vezes que a palavra pode ser formada

	loop2:                                ;loop para obtencao do tamanho do conjunto de letras
		ldurb W11, [X9,X12]
		cmp w11, #0
		b.eq endloop2
		add X12, X12, 1
		b loop1
		endloop2:

	mov X16, X12                          ;X16 = tamanho do conjunto de letras
	subi X16, X16, 1                      ;X16 = endereco do ultimo caracter do conjunto de caracter
	mov X12, 0

	loop:
		ldurb W11, [X10,X12]              ;Carrega em W11 o caractere i da palavra
		cmp W11, #0                       ;Verifica se a palavra acabou
		b.eq endloop                      ;Se a palavra acabou pula para o fim do loop
		mov X14, 0                        ;X14 = 0, zera o contador j
		procura:
			ldurb W13, [X9,X14]           ;Carrega em W13 o caractere j do conjunto
			cmp W13, #0                   ;Verifica se chegou ao fim do conjunto
			b.eq return                   ;Se chegou ao fim do conjunto e nao foi encontrado o caractere o jogo acabou
			cmp W11, W13                  ;Compara o caractere i da palavra com o caractere j do conjunto
			b.eq iguais                   
			addi X14, X14, 1              ;incrementa j
			b procura                     ;volta comparar com o proximo caractere do conjunto
			iguais:
			                              ;Se os caracteres forem iguais, ele devera ser excluido do conjunto
				ldurb W11, [X9,X16]       ;Carrega em W11 o ultimo caractere do conjunto
				sturb W11, [X9,X14]       ;Guarda W11 na posicao j do conjunto (onde se encontrava o caracter a ser excluido)
				mov W11, 0
				sturb W11, [X9,X16]       ;Move o caracter de fim de frase para a ultima posicao do conjunto
				subi X16, X16, 1          ;Diminui uma posicao do conjunto
				addi X12, X12, 1          ;Incremente i
				b loop                    ;Volta ao loop para encontrar a proxima letra
		endloop:
			addi X17, X17, 1              ;Se a palavra acabou  todas as letras foram encontradas, logo a palavra pode ser formada
			                              ;Incrementa a quantidade de vezes que a palavra pode ser formada
			mov X12, 0                    ;Faz i = 0
			b loop                        ;Volta ao loop para ver se a palavra pode ser formada mais uma vez

return:
	mov X0, X17
	br	X30
