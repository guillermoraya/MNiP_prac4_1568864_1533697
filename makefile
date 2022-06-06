update: clean all

all: pendol

pendol: pendol.c RK4.c
	gcc -Wall RK4.c pendol.c -o pendol -lm

clean: 
	rm pendol

cleanP:
	rm points*
