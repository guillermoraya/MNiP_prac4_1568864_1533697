#include math.h


void RK4 (double (*f1)(double, double, double, void*),
			 double (*f2)(double, double, double, void*), 
			 double *x, double *y, double x0, double y0, 
			 double t0, double tf, int n, void *prm,
			 void *prm2)
{
	double x_0 = x0, y_0 = y0;
	double alpha = prm[0];
	double quocient = prm2[0];
	double h = (tf - t0)/n

	double k1[2], k2[2], k3[2], k4[2];

	for (int i = 0; i<n; i++) {
		k1[0] = x_0;
		k1[1] = alpha * y_0 - quocient * sin(y_0);
		k2[0] = x_0 + h/2 * k1[0];
		k2[1] = alpha * (y_0+h/2 * k1[1]) - quocient * sin((y_0+h/2 * k1[1]));
		k3[0] = x_0 + h/2 * k2[0];
		k3[1] = alpha * (y_0+h/2 * k2[1]) - quocient * sin((y_0+h/2 * k2[1]));
		k4[0] = x_0 + h * k3[0];
		k4[1] = alpha * (y_0+h * k3[1]) - quocient * sin((y_0+h * k3[1]));

	}
	return;
}
