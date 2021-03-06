// Universidad de los Andes
// F�sica computacional
// Tarea 7
// Archivo con el c�lculo de las funciones
// Autores:
//	Andr�s Felipe Garc�a Albarrac�n
//	Andrea Rozo M�ndez

#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#define R0 1.7 // [r]
#define v0 0 // [cm/s]
#define P0 5.6e-6 // [m/r*t**2]
#define M 1.0e5 // [m]
#define m 1.0 // [m]
#define gamma 1.666666
#define G 6.6738e-9
#define pi 3.1415972

double functionR (double t, double r, double v)
{
       return (v);
}

double functionV (double t, double r, double v)
{
	double cte = 4*pi*P0*pow(R0,5)/m; // 5 = 3*5/3
	double r2 = pow(r,2);
	double r3 = r*r*r;
	return (-G*M/r2 + cte/r3);
}
