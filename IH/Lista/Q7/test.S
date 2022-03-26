	.globl test
test:

	mov X9, X0                     ;X9 = endereco da string
	mov X11, 0                     ;X11 = contador de caracter da string
	mov X12, 0                     ;X12 = pontuacao
	
	mov X13, 0                     ;X13 = identificador de jogador

	b loop

	jogador2:                      ;Calcula a pontuacao do jogador 2
		mov X9, X1                 ;Muda a palavra do jogador 2 para o registrado X9
		mov X11, 0                 ;Zera o contador X11
		mov X14, X12               ;Salva a Pontuacao do jogador 1 no registrador X14
		mov X12, 0                 ;Zera o registrador X12

		mov X13, 1                 ;Seta o identificador de jogador para 1, (identificador do jogador 2)

		b loop                     ;Pula para o loop para calcular

	fimdejogo:                     ;Se as duas pontuacoes foram obtidas o jogo acabou
		cmp X14,X12            
		b.gt vitoriajogador1       ;Se a pontuacao do jogador 1 (X14) for maior que a pontuacao do jogador 2 (X12)
		cmp X14, X12
		b.lt vitoriajogador2       ;Se a pontuacao do jogador 1 (X14) for menor que a pontuacao do jogador 2 (X12)
		b empate                   ;Se a pontuacao do jogador 1 (X14) for igual que a pontuacao do jogador 2 (X12)
		vitoriajogador1:
			mov X0, 65             ;Se o jogador 1 venceu, retorna 'A'
			b return
		vitoriajogador2:
			mov X0, 66             ;Se o jogador 2 venceu, retorna 'B'
			b return
		empate:
			mov X0, 69             ;Se o deu empate, retorna 'E'
			b return

loop:
	ldurb W10, [X9,X11]            ;Carrega no registrador X10 o proximo caracter da palavra
	add X11, X11, 1                ;Incrementa o contador
	cmp W10, #0                    ;Verifica se acabou a palavra
	b.eq endloop                   ;Se a palavra acabou pula para o fim do loop

	cmp W10, #65                   ;Faz as comparacoes
	b.eq grupo1
	cmp W10, #69
	b.eq grupo1
	cmp W10, #73
	b.eq grupo1
	cmp W10, #79
	b.eq grupo1
	cmp W10, #85
	b.eq grupo1

	cmp W10, #68
	b.eq grupo2
	cmp W10, #71
	b.eq grupo2
	cmp W10, #84
	b.eq grupo2

	cmp W10, #66
	b.eq grupo3
	cmp W10, #67
	b.eq grupo3
	cmp W10, #77
	b.eq grupo3
	cmp W10, #78
	b.eq grupo3
	cmp W10, #80
	b.eq grupo3

	cmp W10, #70
	b.eq grupo4
	cmp W10, #72
	b.eq grupo4
	cmp W10, #86
	b.eq grupo4
	cmp W10, #87
	b.eq grupo4
	cmp W10, #89
	b.eq grupo4

	cmp W10, #75
	b.eq grupo5
	cmp W10, #82
	b.eq grupo5
	cmp W10, #83
	b.eq grupo5

	cmp W10, #74
	b.eq grupo6
	cmp W10, #76
	b.eq grupo6
	cmp W10, #88
	b.eq grupo6

	cmp W10, #81
	b.eq grupo7
	cmp W10, #90
	b.eq grupo7

	b loop                         ;Se nao for nenhuma letra especificada, retorna ao loop
	
	grupo1:                  
		addi X12, X12, 1           ;Incrementa o X12 onde esta armazenada a pontuacao do jogador
		b loop                     ;Volta para o loop para adicionar a pontuacao da proxima letra
	grupo2:
		addi X12, X12, 2
		b loop
	grupo3:
		addi X12, X12, 3
		b loop
	grupo4:
		addi X12, X12, 4
		b loop
	grupo5:
		addi X12, X12, 5
		b loop
	grupo6:
		addi X12, X12, 8
		b loop
	grupo7:
		addi X12, X12, 10
		b loop
	
	endloop:                       ;Se a palavra acabou o loop vai acabar
		cmp X13, 0
		b.eq jogador2              ;Se a palavra for a do jogador 1, o loop vai retornar para calcular a pontuacao do jogador 2
		cmp X13, 1
		b.eq fimdejogo             ;Se a palavra for a do jogador 2, o jogo acaba
	
return:
	br	X30
