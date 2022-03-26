org 0x7e00
jmp 0x0000:start

data:
	
	;Dados do projeto...
    intro db 'CARREGANDO...',0
    menu1 db 'Bem vindo ao desafio do charada!!!',0
    menu2 db 'Opcoes:',0
    menu3 db '1 - Jogar',0
    menu4 db '2 - Instrucoes',0
    menu5 db '3 - Criadores',0
    menu6 db '4 - Sair',0
    instrucao1 db 'Para cada charada digite...',0
    instrucao2 db 'c - se souber a resposta da charada',0
    instrucao3 db 'p - se quiser pular a charada',0
    instrucao4 db 'd - se quiser uma dica',0
    instrucao5 db 'Voce so pode pular 5 charadas',0
    instrucao6 db 'Voce so pode pedir 4 dicas',0
    instrucao7 db 'Digite m para voltar ao menu',0
    criador1 db 'Criadores:',0
    criador2 db 'EMANOEL RAFAEL MELO FERREIRA DA SILVA',0
    criador3 db 'CARLOS EDUARDO VIEIRA BRAGA',0
    criador4 db 'MARCOS WANDERSON DOS SANTOS ALVES',0
    sair1 db 'Obrigado por jogar',0
    fimdejogo db 'Parabens! Voce resolveu todas as charadas :)',0 ;44
    
    intro2 db 'O QUE EH O QUE EH...',0 ;18
    resposta times 50 db 0
    mensagem1 db 'SUAS DICAS ACABARAM',0
    mensagem2 db 'SEUS PULOS ACABARAM',0
    mensagem3 db '                                                            ',0 ;60
    mensagem4 db '##RESPOSTA ERRADA##',0
    mensagem5 db 'RESPOSTA: ',0 ;10
    mensagem6 db 'RESPOSTA CORRETA!!!',0

    charada1a db 'Eh alta quando jovem e baixinha quando fica velha.',0 ;50
    charada1b db 'Alem disso, eh rapida quando eh magra e lenta quando eh gorda.',0 ;61
    charada2a db 'Quando voce me vira de lado, sou tudo.',0 ;38
    charada2b db 'Quando me corta ao meio, nao sou nada.',0 ;38
    charada3 db 'Qual e a melhor cura para a caspa?',0 ;34
    charada4 db 'O que tem no final do arco-iris?',0 ;32
    charada5 db 'Qual o animal que nao vale mais nada.',0 ;37
    charada6 db 'Da muitas voltas e nao sai do lugar.',0 ;36
    charada7 db 'Quanto mais rugas tem mais novo eh.',0 ;34
    charada8 db 'O que anda com os pes na cabeca.',0 ;32
    charada9 db 'O que o nadador faz para bater o recorde?',0 ;41
    charada10 db 'O que o tomate foi tirar no banco?',0 ;34
    charada11 db 'O melhor lado do Cin?',0 ;21

    resposta1 db 'a vela',0
    resposta2 db 'o numero 8',0
    resposta3 db 'a calvicie',0
    resposta4 db 'a letra s',0
    resposta5 db 'o javali',0
    resposta6 db 'o relogio',0
    resposta7 db 'o pneu',0
    resposta8 db 'o piolho',0
    resposta9 db 'nada',0
    resposta10 db 'o extrato',0
    resposta11 db 'o lado de fora',0

    dica1 db 'Comeca com v',0
    dica2 db 'Eh um numero',0
    dica3 db 'Comeca com c',0
    dica4 db 'Eh uma letra',0
    dica5 db 'Porco selvagem',0
    dica6 db 'Comeca com r',0
    dica7 db 'Carro tem',0
    dica8 db 'Comeca com p',0
    dica9 db 'Muito facil, nao precisa de dica',0
    dica10 db 'Usa na macarronada',0
    dica11 db 'O lado bom de toda a UFPE',0

start:
    xor ax, ax
    mov ds, ax
    mov es, ax
    ;Código do projeto...

    mov bl,2
    call modovideo

    mov dl,33
    mov dh,14
    mov si,intro
    call imprimetextopausado

    mov ax,2
    call delay

    call menu

    mov ax,20
    call delay

    call animacao

    mov bl,15
    call modovideo
jmp $

menu:
    .loop1
    mov bl,4
    call modovideo

    mov dl,23           ;coluna
    mov dh,12           ;linha
    mov si,menu1
    call imprimetexto

    mov dl,33           
    mov dh,14           
    mov si,menu3
    call imprimetexto

    mov dl,33           
    mov dh,15           
    mov si,menu4
    call imprimetexto

    mov dl,33           
    mov dh,16           
    mov si,menu5
    call imprimetexto

    mov dl,33           
    mov dh,17           
    mov si,menu6
    call imprimetexto

    mov al,'0'
    .loopmenu
        cmp al,'1'
        je .opcao1
        cmp al,'2'
        je .opcao2
        cmp al,'3'
        je .opcao3
        cmp al,'4'
        je .opcao4
        call getchar
        jmp .loopmenu
        .opcao1
            call jogar
            jmp .loop1
        .opcao2
            call instrucoes
            jmp .loop1
        .opcao3
            call criadores
            jmp .loop1
        .opcao4
            call sair
            jmp .endloopmenu
        .endloopmenu
ret

menucharada:

    mov al,'a'
    .loop2
        cmp al,'c'
        je .tentativa
        cmp al,'d'
        je .dica
        cmp al,'p'
        je .pula
        call getchar
        jmp .loop2
        .tentativa:
            mov si,mensagem5
            mov dl,4         ;coluna
            mov dh,25        ;linha
            call imprimetexto

            mov di,resposta
            call gets
            mov ah,0
            jmp .endloop2
        .dica:
            pop dx ;salvar o endereço de retorno
            pop bx 

            cmp bx,0
            je .semdicas
            mov ah,1
            dec bx
            push bx
            push dx
            mov bx,15 ;colocando a cor de saida como branca
            jmp .endloop2
            .semdicas:
                push bx
                push dx
                mov bl,9
                mov si,mensagem1
                mov dl,30
                mov dh,22
                call imprimetexto
                mov ax,20
                call delay
                mov si,mensagem3
                mov dl,10
                mov dh,22
                call imprimetexto
                jmp .loop2
        .pula:
            pop dx ;salvar o endereco de retorno
            pop bx
            pop cx
            cmp cx,0
            je .sempulos
            mov ah,2
            dec cx
            push cx
            push bx
            push dx
            mov bx,15 
            jmp .endloop2
            .sempulos:
                push cx
                push bx
                push dx
                mov si,mensagem2
                mov dl,30
                mov dh,22
                mov bl,9
                call imprimetexto
                mov ax,20
                call delay
                mov si,mensagem3
                mov dl,10
                mov dh,22
                call imprimetexto
                jmp .loop2


        .endloop2
ret

respostaerrada:
    mov si,mensagem4
    mov dl,30
    mov dh,22
    call imprimetexto
    mov ax,20
    call delay
    mov si,mensagem3
    mov dl,10
    mov dh,22
    call imprimetexto
    mov si,mensagem3
    mov dl,4
    mov dh,25
    call imprimetexto
ret

respostacorreta:
    mov si,mensagem6
    mov dl,4
    mov dh,26
    call imprimetexto
    mov ax,20
    call delay
ret

jogar:

    mov cx,5        ;pulos
    mov bx,4        ;dicas
    push cx
    push bx

    mov dl,15       ;coluna
    mov dh,14       ;linha
    mov si,charada1a
    call imprimecharada

    mov dl,9       ;coluna
    mov dh,15       ;linha
    mov si,charada1b
    call imprimetexto

    .loop3
        call menucharada

        cmp ah,0
        je .comparar1
        cmp ah,1
        je .printardica1
        cmp ah,2
        je .pularfase1
        .comparar1
            mov di,resposta
            mov si,resposta1
            call strcmp
            cmp ah,1
            je .proxcharada1
            call respostaerrada
            jmp .loop3
            .proxcharada1
                call respostacorreta
                jmp .segundacharada
        .printardica1
            mov si,dica1
            mov dl,34
            mov dh,22
            mov bl,9
            call imprimetexto
            mov ax,20
            call delay
            mov si,mensagem3
            mov dl,10
            mov dh,22
            call imprimetexto
            jmp .loop3
        .pularfase1
            mov si,resposta1
            mov dl,2
            mov dh,27
            mov bl,9
            call imprimetexto
            mov ax,20
            call delay
            jmp .segundacharada
    
    .segundacharada

    mov dl,21       ;coluna
    mov dh,14       ;linha
    mov si,charada2a
    call imprimecharada

    mov dl,21       ;coluna
    mov dh,15       ;linha
    mov si,charada2b
    call imprimetexto

    .loop4
        call menucharada

        cmp ah,0
        je .comparar2
        cmp ah,1
        je .printardica2
        cmp ah,2
        je .pularfase2
        .comparar2
            mov di,resposta
            mov si,resposta2
            call strcmp
            cmp ah,1
            je .proxcharada2
            call respostaerrada
            jmp .loop4
            .proxcharada2
                call respostacorreta
                jmp .terceiracharada
        .printardica2
            mov si,dica2
            mov dl,34
            mov dh,22
            mov bl,9
            call imprimetexto
            mov ax,20
            call delay
            mov si,mensagem3
            mov dl,10
            mov dh,22
            call imprimetexto
            jmp .loop4
        .pularfase2
            mov si,resposta2
            mov dl,2
            mov dh,27
            mov bl,9
            call imprimetexto
            mov ax,20
            call delay
            jmp .terceiracharada

    .terceiracharada

    mov dl,23       ;coluna
    mov dh,14       ;linha
    mov si,charada3
    call imprimecharada

    .loop5
        call menucharada

        cmp ah,0
        je .comparar3
        cmp ah,1
        je .printardica3
        cmp ah,2
        je .pularfase3
        .comparar3
            mov di,resposta
            mov si,resposta3
            call strcmp
            cmp ah,1
            je .proxcharada3
            call respostaerrada
            jmp .loop5
            .proxcharada3
                call respostacorreta
                jmp .quartacharada
        .printardica3
            mov si,dica3
            mov dl,34
            mov dh,22
            mov bl,9
            call imprimetexto
            mov ax,20
            call delay
            mov si,mensagem3
            mov dl,10
            mov dh,22
            call imprimetexto
            jmp .loop5
        .pularfase3
            mov si,resposta3
            mov dl,2
            mov dh,27
            mov bl,9
            call imprimetexto
            mov ax,20
            call delay
            jmp .quartacharada

    .quartacharada

    mov dl,24       ;coluna
    mov dh,14       ;linha
    mov si,charada4
    call imprimecharada

    .loop6
        call menucharada

        cmp ah,0
        je .comparar4
        cmp ah,1
        je .printardica4
        cmp ah,2
        je .pularfase4
        .comparar4
            mov di,resposta
            mov si,resposta4
            call strcmp
            cmp ah,1
            je .proxcharada4
            call respostaerrada
            jmp .loop6
            .proxcharada4
                call respostacorreta
                jmp .quintacharada
        .printardica4
            mov si,dica4
            mov dl,34
            mov dh,22
            mov bl,9
            call imprimetexto
            mov ax,20
            call delay
            mov si,mensagem3
            mov dl,10
            mov dh,22
            call imprimetexto
            jmp .loop6
        .pularfase4
            mov si,resposta4
            mov dl,2
            mov dh,27
            mov bl,9
            call imprimetexto
            mov ax,20
            call delay
            jmp .quintacharada

    .quintacharada

    mov dl,21       ;coluna
    mov dh,14       ;linha
    mov si,charada5
    call imprimecharada

    .loop7
        call menucharada

        cmp ah,0
        je .comparar5
        cmp ah,1
        je .printardica5
        cmp ah,2
        je .pularfase5
        .comparar5
            mov di,resposta
            mov si,resposta5
            call strcmp
            cmp ah,1
            je .proxcharada5
            call respostaerrada
            jmp .loop7
            .proxcharada5
                call respostacorreta
                jmp .sextacharada
        .printardica5
            mov si,dica5
            mov dl,33
            mov dh,22
            mov bl,9
            call imprimetexto
            mov ax,20
            call delay
            mov si,mensagem3
            mov dl,10
            mov dh,22
            call imprimetexto
            jmp .loop7
        .pularfase5
            mov si,resposta5
            mov dl,2
            mov dh,27
            mov bl,9
            call imprimetexto
            mov ax,20
            call delay
            jmp .sextacharada

    .sextacharada


    mov dl,22       ;coluna
    mov dh,14       ;linha
    mov si,charada6
    call imprimecharada

    .loop8
        call menucharada

        cmp ah,0
        je .comparar6
        cmp ah,1
        je .printardica6
        cmp ah,2
        je .pularfase6
        .comparar6
            mov di,resposta
            mov si,resposta6
            call strcmp
            cmp ah,1
            je .proxcharada6
            call respostaerrada
            jmp .loop8
            .proxcharada6
                call respostacorreta
                jmp .setimacharada
        .printardica6
            mov si,dica6
            mov dl,34
            mov dh,22
            mov bl,9
            call imprimetexto
            mov ax,20
            call delay
            mov si,mensagem3
            mov dl,10
            mov dh,22
            call imprimetexto
            jmp .loop8
        .pularfase6
            mov si,resposta6
            mov dl,2
            mov dh,27
            mov bl,9
            call imprimetexto
            mov ax,20
            call delay
            jmp .setimacharada

    .setimacharada

    mov dl,23       ;coluna
    mov dh,14       ;linha
    mov si,charada7
    call imprimecharada

    .loop9
        call menucharada

        cmp ah,0
        je .comparar7
        cmp ah,1
        je .printardica7
        cmp ah,2
        je .pularfase7
        .comparar7
            mov di,resposta
            mov si,resposta7
            call strcmp
            cmp ah,1
            je .proxcharada7
            call respostaerrada
            jmp .loop9
            .proxcharada7
                call respostacorreta
                jmp .oitavacharada
        .printardica7
            mov si,dica7
            mov dl,35
            mov dh,22
            mov bl,9
            call imprimetexto
            mov ax,20
            call delay
            mov si,mensagem3
            mov dl,10
            mov dh,22
            call imprimetexto
            jmp .loop9
        .pularfase7
            mov si,resposta7
            mov dl,2
            mov dh,27
            mov bl,9
            call imprimetexto
            mov ax,20
            call delay
            jmp .oitavacharada

    .oitavacharada

    mov dl,24       ;coluna
    mov dh,14       ;linha
    mov si,charada8
    call imprimecharada

    .loop10
        call menucharada

        cmp ah,0
        je .comparar8
        cmp ah,1
        je .printardica8
        cmp ah,2
        je .pularfase8
        .comparar8
            mov di,resposta
            mov si,resposta8
            call strcmp
            cmp ah,1
            je .proxcharada8
            call respostaerrada
            jmp .loop10
            .proxcharada8
                call respostacorreta
                jmp .nonacharada
        .printardica8
            mov si,dica8
            mov dl,34
            mov dh,22
            mov bl,9
            call imprimetexto
            mov ax,20
            call delay
            mov si,mensagem3
            mov dl,10
            mov dh,22
            call imprimetexto
            jmp .loop10
        .pularfase8
            mov si,resposta8
            mov dl,2
            mov dh,27
            mov bl,9
            call imprimetexto
            mov ax,20
            call delay
            jmp .nonacharada

    .nonacharada

    mov dl,19       ;coluna
    mov dh,14       ;linha
    mov si,charada9
    call imprimecharada

    .loop11
        call menucharada

        cmp ah,0
        je .comparar9
        cmp ah,1
        je .printardica9
        cmp ah,2
        je .pularfase9
        .comparar9
            mov di,resposta
            mov si,resposta9
            call strcmp
            cmp ah,1
            je .proxcharada9
            call respostaerrada
            jmp .loop11
            .proxcharada9
                call respostacorreta
                jmp .decimacharada
        .printardica9
            mov si,dica9
            mov dl,24
            mov dh,22
            mov bl,9
            call imprimetexto
            mov ax,20
            call delay
            mov si,mensagem3
            mov dl,10
            mov dh,22
            call imprimetexto
            jmp .loop11
        .pularfase9
            mov si,resposta9
            mov dl,2
            mov dh,27
            mov bl,9
            call imprimetexto
            mov ax,20
            call delay
            jmp .decimacharada

    .decimacharada

    mov dl,23       ;coluna
    mov dh,14       ;linha
    mov si,charada10
    call imprimecharada

    .loop12
        call menucharada

        cmp ah,0
        je .comparar10
        cmp ah,1
        je .printardica10
        cmp ah,2
        je .pularfase10
        .comparar10
            mov di,resposta
            mov si,resposta10
            call strcmp
            cmp ah,1
            je .proxcharada10
            call respostaerrada
            jmp .loop12
            .proxcharada10
                call respostacorreta
                jmp .charadaonze
        .printardica10
            mov si,dica10
            mov dl,31
            mov dh,22
            mov bl,9
            call imprimetexto
            mov ax,20
            call delay
            mov si,mensagem3
            mov dl,10
            mov dh,22
            call imprimetexto
            jmp .loop12
        .pularfase10
            mov si,resposta10
            mov dl,2
            mov dh,27
            mov bl,9
            call imprimetexto
            mov ax,20
            call delay
            jmp .charadaonze

    .charadaonze

    mov dl,29       ;coluna
    mov dh,14       ;linha
    mov si,charada11
    call imprimecharada

    .loop13
        call menucharada

        cmp ah,0
        je .comparar11
        cmp ah,1
        je .printardica11
        cmp ah,2
        je .pularfase11
        .comparar11
            mov di,resposta
            mov si,resposta11
            call strcmp
            cmp ah,1
            je .proxcharada11
            call respostaerrada
            jmp .loop13
            .proxcharada11
                call respostacorreta
                jmp .fim
        .printardica11
            mov si,dica11
            mov dl,27
            mov dh,22
            mov bl,9
            call imprimetexto
            mov ax,20
            call delay
            mov si,mensagem3
            mov dl,10
            mov dh,22
            call imprimetexto
            jmp .loop13
        .pularfase11
            mov si,resposta11
            mov dl,2
            mov dh,27
            mov bl,9
            call imprimetexto
            mov ax,20
            call delay
            jmp .fim

    .fim

    mov dl,18
    mov dh,14
    mov si,fimdejogo
    call imprimemenu
    mov ax,20
    call delay

    pop bx
    pop cx

ret

instrucoes:
    mov bl,6
    call modovideo

    mov dl,26           ;coluna
    mov dh,11           ;linha
    mov si,instrucao1
    call imprimetexto

    mov dl,22           ;coluna
    mov dh,13           ;linha
    mov si,instrucao2
    call imprimetexto

    mov dl,22           
    mov dh,14           
    mov si,instrucao3
    call imprimetexto

    mov dl,22           
    mov dh,15           
    mov si,instrucao4
    call imprimetexto

    mov dl,22           
    mov dh,16           
    mov si,instrucao5
    call imprimetexto

    mov dl,22           
    mov dh,17           
    mov si,instrucao6
    call imprimetexto

    mov dl,22           
    mov dh,20           
    mov si,instrucao7
    call imprimetexto

    mov al,'0'
    .loopinstrucao
        cmp al,'m'
        je .endloopinstrucao
        call getchar
        jmp .loopinstrucao
        .endloopinstrucao
ret

criadores:
    mov bl,5
    call modovideo

    mov dl,0           ;coluna
    mov dh,0           ;linha
    mov si,criador1
    call imprimetexto

    mov dl,0           
    mov dh,2           
    mov si,criador2
    call imprimetexto

    mov dl,0           
    mov dh,4           
    mov si,criador3
    call imprimetexto

    mov dl,0           
    mov dh,6           
    mov si,criador4
    call imprimetexto

    mov dl,0           
    mov dh,9           
    mov si,instrucao7
    call imprimetexto

    mov al,'0'
    .loopcriadores
        cmp al,'m'
        je .endloopcriadores
        call getchar
        jmp .loopcriadores
        .endloopcriadores
ret

sair:
    mov bl,15
    call modovideo

    mov dl,31           ;coluna
    mov dh,14           ;linha
    mov si,sair1
    call imprimetexto
ret

imprimetexto:

    mov bh,0
    mov ah,0x02
    int 10h 

    mov cx,0
    call prints
ret

imprimetextopausado:

    mov bh,0
    mov ah,0x02
    int 10h 

    mov cx,1
    call prints
ret

imprimemenu: ;imprime menu
    mov bl,15
    call modovideo

    mov bh,0
    mov ah,0x02
    int 10h 

    mov cx,0
    call prints
ret

imprimecharada:
    mov bl,9
    call modovideo

    push si
    push dx
    mov dl,31
    mov dh,6
    mov si,intro2
    call imprimetextopausado
    mov ax,5
    call delay

    pop dx
    pop si

    call imprimetexto

ret

delay:
    push bx
    mov bx,ax
    .loopdelay
        cmp bx,0
        je .endloopdelay
        dec bx
        mov cx, 01h
        mov dx, 80a0h
        mov ah, 86h
        int 15h
        jmp .loopdelay
        .endloopdelay
    pop bx
ret

getchar:
 	mov ah, 0x00
 	int 16h
ret

putchar:
    mov ah,0x0e
    int 10h
ret

delchar:
  mov al, 0x08          ; backspace
  call putchar
  mov al, ' '
  call putchar
  mov al, 0x08          ; backspace
  call putchar
ret

endl:
  mov al, 0x0a          ; line feed
  call putchar
  mov al, 0x0d          ; carriage return
  call putchar
ret

prints:             ; mov si, string
 	.loop:
 		lodsb           ; bota character em al 
 		cmp al, 0
 		je .endloop
        cmp cx,0
        je .continua
        push ax
        mov ax,1
        call delay
        pop ax
        .continua
            call putchar
            jmp .loop
 	.endloop:
ret

modovideo:

    mov ah, 0x00
    mov al, 12h
    int 10h

ret

gets:                 ; mov di, string
  xor cx, cx          ; zerar contador
  .loop1:
    call getchar
    cmp al, 0x08      ; backspace
    je .backspace
    cmp al, 0x0d      ; carriage return
    je .done
    cmp cl, 50        ; string limit checker
    je .loop1
    
    stosb
    inc cl
    call putchar
    
    jmp .loop1
    .backspace:
      cmp cl, 0       ; is empty?
      je .loop1
      dec di
      dec cl
      mov byte[di], 0
      call delchar
    jmp .loop1
  .done:
  mov al, 0
  stosb
  call endl
ret

strcmp:             ; mov si, string1, mov di, string2
	.loop1:
		lodsb
		cmp al, byte[di]
		jne .notequal
		cmp al, 0
		je .equal
		inc di
		jmp .loop1
	.notequal:
		mov ah,0
	ret
	.equal:
		mov ah,1
ret

pixel:
    mov ah, 0ch
    mov bh, 0
    mov al, 4h
    int 10h
ret

animacao:
    push dx
    push cx

    call modovideo

    mov dx,80
    .bloco1
        mov cx,80
        .loopbloco1
            cmp cx,240
            je .proxlinhabloco1
            call pixel
            inc cx
            jmp .loopbloco1
            .proxlinhabloco1
                cmp dx,120
                je .fimbloco1
                inc dx
                jmp .bloco1
                .fimbloco1

    mov dx,120
    .bloco2
        mov cx,80
        .loopbloco2
            cmp cx,120
            je .proxlinhabloco2
            call pixel
            inc cx
            jmp .loopbloco2
            .proxlinhabloco2
                cmp dx,400
                je .fimbloco2
                inc dx
                jmp .bloco2
                .fimbloco2

    mov dx,240
    .bloco3
        mov cx,120
        .loopbloco3
            cmp cx,200
            je .proxlinhabloco3
            call pixel
            inc cx
            jmp .loopbloco3
            .proxlinhabloco3
                cmp dx,280
                je .fimbloco3
                inc dx
                jmp .bloco3
                .fimbloco3

    mov dx,80
    .bloco4
        mov cx,280
        .loopbloco4
            cmp cx,320
            je .proxlinhabloco4
            call pixel
            inc cx
            jmp .loopbloco4
            .proxlinhabloco4
                cmp dx,120
                je .fimbloco4
                inc dx
                jmp .bloco4
                .fimbloco4
    
    mov dx,160
    .bloco5
        mov cx,280
        .loopbloco5
            cmp cx,320
            je .proxlinhabloco5
            call pixel
            inc cx
            jmp .loopbloco5
            .proxlinhabloco5
                cmp dx,400
                je .fimbloco5
                inc dx
                jmp .bloco5
                .fimbloco5

    mov dx,80
    .bloco6
        mov cx,360
        .loopbloco6
            cmp cx,560
            je .proxlinhabloco6
            call pixel
            inc cx
            jmp .loopbloco6
            .proxlinhabloco6
                cmp dx,120
                je .fimbloco6
                inc dx
                jmp .bloco6
                .fimbloco6

    mov dx,120
    .bloco7
        mov cx,360
        .loopbloco7
            cmp cx,400
            je .proxlinhabloco7
            call pixel
            inc cx
            jmp .loopbloco7
            .proxlinhabloco7
                cmp dx,400
                je .fimbloco7
                inc dx
                jmp .bloco7
                .fimbloco7

    mov dx,120
    .bloco8
        mov cx,440
        .loopbloco8
            cmp cx,480
            je .proxlinhabloco8
            call pixel
            inc cx
            jmp .loopbloco8
            .proxlinhabloco8
                cmp dx,400
                je .fimbloco8
                inc dx
                jmp .bloco8
                .fimbloco8

    mov dx,120
    .bloco9
        mov cx,520
        .loopbloco9
            cmp cx,560
            je .proxlinhabloco9
            call pixel
            inc cx
            jmp .loopbloco9
            .proxlinhabloco9
                cmp dx,400
                je .fimbloco9
                inc dx
                jmp .bloco9
                .fimbloco9

    mov ax,10
    call delay
    pop cx
    pop dx
ret

