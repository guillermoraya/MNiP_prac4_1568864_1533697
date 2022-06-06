#include "RK4.h"


double f1(double x, double y, double t, void* args);
double f2(double x, double y, double t, void* args);

int main(int argc, char* argv[])
{
	// Calling this program has the following syntax:
	//		
	//			./pendol α m L x0 y0 t0 tf n
	if(argc!=9)
	{
		// If the number of parameters given to the program is not adequate,
		// we'll display this error message and kill the execution.
		fprintf(stderr,"ERROR: la crida ha de ser de la forma './pendol α m L x0 y0 t0 tf n'.\n");
		return -1;
	}
	// Let's read the values from argv[]
	double x,y;
	double alpha = (double) atof(argv[1]);
	double m = (double) atof(argv[2]);
	double L = (double) atof(argv[3]);
	double x0 = (double) atof(argv[4]);
	double y0 = (double) atof(argv[5]);
	int t0 = atof(argv[6]);
	int tf = atof(argv[7]);
	int n=atof(argv[8]);	
	double args[3]={alpha,m,L};
	
	if(t0>tf)
	{
		fprintf(stderr,"ERROR: 'tf' (temps final) ha de ser major que 't0' (temps inicial).\n");
		fprintf(stderr,"RECORDATORI: la crida ha de ser de la forma './pendol α m L x0 y0 t0 tf n'.\n");
		return -1;
	}
	
	x=x0;
	y=y0;
	printf("%8s %8s %8s\n","t", "x", "y");
	for(int t=t0; t<tf; t++)
	{
		RK4(&f1, &f2, &x, &y, x, y, (double) t, (double) t+1, n,&args,&args);
		printf("%8d %8f %8f\n",t,x,y);
	}
	
	return 0;
}


double f1(double x, double y, double t, void* args)
{
	return y;
}
double f2(double x, double y, double t, void* args)
{
	double alpha = *(double *)args;
	args += sizeof(double);
	double m = *(double *)args;
	args += sizeof(double);
	double L = *(double *)args;
	
	return -alpha * y - sin(x)*m/L;
}//plot "points.txt" u 2:3
