	.globl test
test:

	cmp X1,#0
	b.lt return             ;se a (que esta armazenado no registrador X1) for < 0, a condicao nao é satisfeita
	cmp X2,#32
	b.gt return             ;se b (que esta armazenado no registrador X2) for > 32, a condicao nao é satisfeita
	cmp X3,#25
	b.le return             ;se c (que esta armazenado no registrador X3) for <= 25, a condicao nao é satisfeita
	mov X0,1                ;Se todas as condicoes foram satisfeitas X = 1

return:
	br	X30
