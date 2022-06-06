update: clean all

all: pendol

pendol: pendol.c RK4.c
	gcc -Wall RK4.c pendol.c -o pendol -lm

clean: 
	rm pendol

cleanPoints:
	rm points*
	
cleanPlot:
	rm plot.png
