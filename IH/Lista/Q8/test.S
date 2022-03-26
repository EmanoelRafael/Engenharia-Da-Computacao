	.globl test
test:

	mov X11,10
	inicio:
		cmp X0,0
		b.eq return
		udiv X10,X0,X11          ; X10 = n/10 (parte inteira)
		mul X10,X10,X11          ; X10 = (n/10)*10
		sub X10,X0,X10           ; X10 = n%10 (X10 recebe o resto da divisao)               
		udiv X0,X0,X11           ; X0 = n/10(parte inteira)
		mov X12,1                ; X12 = 1
		
		;Fatora o numero armazenado em X10
		fatoracao:
			cmp X10,0       
			b.eq end             ; if(i = 0) acabou a fatoracao
			mul X12,X10,X12      ; r = i*r 
			subi X10,X10,1       ; i = i - 1
			b fatoracao      
			end:
				add X9,X9,X12    ;soma = soma + fatorial do algorismo X10
				b inicio         ;volta para calcular o fatorial do proximo algorismo
return:
	mov X0,X9
	br	X30
