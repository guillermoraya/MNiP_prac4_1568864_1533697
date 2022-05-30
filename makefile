update: clean all

all: pendol

pendol: pendol.c RK4.c
	gcc pendol.c RK4.c -o pendol -lm

clean: 
	rm pendol
