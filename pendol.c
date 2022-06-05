#include "RK4.h"
#include <stdio.h>
#include <stdlib.h>


double f1(double x, double y, double t, void* args);
double f2(double x, double y, double t, void* args);

int main(int argc, char* argv[])
{
	// Calling this program has the following syntax:
	//		
	//			./pendol α m L x0 y0 t0 tf n
	// Let's read the values from argv[]

	if(argc!=9)
	{
		fprintf(stderr,"ERROR: la crida ha de ser de la forma './pendol α m L x0 y0 t0 tf n'.\n");
		return -1;
	}
	
	double x,y;
	double alpha = (double) atof(argv[1]);
	double m = (double) atof(argv[2]);
	double L = (double) atof(argv[3]);
	double x0 = (double) atof(argv[4]);
	double y0 = (double) atof(argv[5]);
	double t0 = (double) atof(argv[6]);
	double tf = atof(argv[7]);
	int n=atof(argv[8]);
	double *ret, *ret2, *prm, *prm2;
	
	//f1(x0,y0, t0, ret);
	//f2(x0, y0, t0, alpha, m, L, ret2);
	
	double args_f2[3]={alpha,m,L};

	RK4(&f1, &f2, &x, &y, x0, y0, t0, tf, n, &args_f2, &prm2);

	printf("%lf %lf %lf", tf, x, y);
	
	return 0;
}


double f1(double x, double y, double t, void* args)
{
	return x;
}
double f2(double x, double y, double t, void* args)
{
	double alpha = args[0];
	double m = args[1];
	double L = args[2];
	return -alpha * y - m*sin(y)/L;
}
