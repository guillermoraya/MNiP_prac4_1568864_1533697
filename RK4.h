void RK4 (double (*f1)(double, double, double, void*),
			 double (*f2)(double, double, double, void*), 
			 double *x, double *y, double x0, double y0, 
			 double t0, double tf, int n, void *prm,
			 void *prm2);
