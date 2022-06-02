#include <math.h>


void RK4 (double (*f1)(double, double, double, void*),
			 double (*f2)(double, double, double, void*), 
			 double *x, double *y, double x0, double y0, 
			 double t0, double tf, int n, void *prm,
			 void *prm2)
{
	double k[5]; //K per a la dimensió 'x'.
	double l[5]; //L són com els K però per a la dimensió 'y'.
	double h = (tf-t0)/(double)n; //Amplada dels subintervals.
	double t; //Variable per al pas del temps.
	double aux_f1,aux_f2; //Variables auxiliars per a emmagatzemar els valors de les funcions f1 i f2.

	// Inicialització de variables de espai ('x' i 'y') i temps ('t').
	*x = x0;
	*y = y0;
	t = t0;

	// Bucle del RK4 en dues dimensions.
	for(int i = 0; i < n; i++)
	{
		// Actualitzem la variable 't' per a indicar el pas del temps.
		t = t0 + i*h;

		// Calculem els valors de les 'slopes' en dimensió 'x' i 'y' a punts intermitjos.
		f1(*x,*y,t,&aux_f1);
		k[0] = h*aux_f1;
		f2(*x,*y,t,&aux_f2);
		l[0] = h*aux_f2;

		f1(*x+k[0]/2,*y+l[0]/2,t+h/2,&aux_f1);
		k[1] = h*aux_f1;
		f2(*x+k[0]/2,*y+l[0]/2,t+h/2,&aux_f2);
		l[1] = h*aux_f2;

		f1(*x+k[1]/2,*y+l[1]/2,t+h/2,&aux_f1);
		k[2] = h*aux_f1;
		f2(*x+k[1]/2,*y+l[1]/2,t+h/2,&aux_f2);
		l[2] = h*aux_f2;

		f1(*x+k[2],*y+l[2],t+h,&aux_f1);
		k[3] = h*aux_f1;
		f2(*x+k[2],*y+l[2],t+h,&aux_f2);
		l[3] = h*aux_f2;

		// ... i calculem els valors aproximats de 'x' i 'y' per al temps actual.
		*x += (k[0] + 2*k[1] + 2*k[2] + k[3])/6;
		*y += (l[0] + 2*l[1] + 2*l[2] + l[3])/6;
	}
}
