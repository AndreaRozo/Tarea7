// Universidad de los Andes
// Física computacional
// Tarea 6
// Archivo con el cálculo de las pendientes
// Autores:
//	Andrés Felipe García Albarracín
//	Andrea Rozo

#include "functions.h"

/**
* Calcula los coeficientes de las pendientes k1, k2, k3 y k4
*/
void calK(double t, double r, double v, double h, double *k1, double *k2, double *k3, double *k4)
{
	k1[0] = functionR(t,r,v);
	k1[1] = functionV(t,r,v);

	k2[0] = functionX(t+h/2,r+k1[0]*h/2,v+k1[1]*h/2);
	k2[1] = functionY(t+h/2,r+k1[0]*h/2,v+k1[1]*h/2);
	
	k3[0] = functionX(t+h/2,r+k2[0]*h/2,v+k2[1]*h/2);
	k3[1] = functionY(t+h/2,r+k2[0]*h/2,v+k2[1]*h/2);
	
	k4[0] = functionX(t+h/2,r+k3[0]*h,v+k3[1]*h);
	k4[1] = functionY(t+h/2,r+k3[0]*h,v+k3[1]*h);
}

/**
* Calcula el vector de pendientes
*/
double slopeXYZ(double t, double r, double v, double h, double *k1, double *k2, double *k3, double *k4, double *slope)
{
	calK(t, r, v, h, k1, k2, k3, k4);
	slope[0] = (k1[0] + 2*k2[0] + 2*k3[0] + k4[0])/6;
	slope[1] = (k1[1] + 2*k2[1] + 2*k3[1] + k4[1])/6;
}
