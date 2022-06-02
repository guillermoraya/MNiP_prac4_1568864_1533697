#include "RK4.h"

void f1(double x, double y, double t, double* ret);
void f2(double x, double y, double t, double* ret);

int main(int argc, char* argv[])
{
	// Calling this program has the following syntax:
	//		
	//			./pendol α m L x0 y0 t0 tf n
	// Let's read the values from argv[]

	if(argc!=9)
	{
		fprintf(stderr, "ERROR: la crida ha de ser de la forma './pendol α m L x0 y0 t0 tf n'\n");
		return -1;
	}
	
	double x,y;
	double alpha=atol(argv[1]);
	double m=atol(argv[2]);
	double L=atol(argv[3]);
	double x0=atol(argv[4]);
	double y0=atol(argv[5]);
	double t0=atol(argv[6]);
	double tf=atol(argv[7]);
	double n=atol(argv[8]);
	
	/*TODO: Completar el main.*/
	
	return 0;
}


void f1(double x, double y, double t, double* ret)
{
	// TODO: Descobrir quina equació hem de posar aquí
	// TODO: Implementar f1
	*ret = 0;
}
void f2(double x, double y, double t, double* ret)
{
	// TODO: Descobrir quina equació hem de posar aquí
	// TODO: Implementar f2
	*ret = 0
}
