#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "RK4.h"

void f1(double x, double y, double t, double* ret);
void f2(double x, double y, double t, double alpha, double m, double L, double* ret);

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
	double *ret, *ret2, *prm, *prm2;
	
	f1(x0,y0, t0, &ret);
	f2(x0, y0, t0, alpha, m, L, &ret2);

	RK4(ret, ret2, &x, &y, x0, y0, t0, tf, n, &prm, &prm2);

	printf("%lf %lf %lf", tf, x, y);
	
	return 0;
}


void f1(double x, double y, double t, double* ret)
{
	*ret = x;
}
void f2(double x, double y, double t, double alpha, double m, double L, double* ret)
{
	*ret = -alpha * y - m/L sin(y);
}
