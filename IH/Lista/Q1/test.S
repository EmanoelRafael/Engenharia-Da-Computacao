	.globl test
test:

	mov X0,X1                   ;m = a
	sub X9,X2,X0                ;X9 = b - m
	cbz X9,igual                ;se X9 = 0, entao b == m
	sub X0,X1,X2                ;Senao, b =! m e m = a - b
	b return

igual:
	sub X0,X2,X1                ;Se b == m entao m = b - a
	b return

return:
	br	X30
