// Universidad de los Andes
// Física computacional
// Tarea 7
// Archivo con el cálculo de las funciones
// Autores:
//	Andrés Felipe García Albarracín
//	Andrea Rozo Méndez

#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#define R0 1.7 // [r]
#define v0 0 // [cm/s]
#define P0 5.6e-6 // [m/r*t**2]
#define M 1.0e5 // [m]
#define m 1.0 // [m]
#define gamma 5/3
#define G 6.6738e-9
#define pi 3.1415972

double functionR (double t, double r, double v)
{
       return (v);
}

double functionV (double t, double r, double v)
{
	double cte = 4*pi*P0*pow(R0,3*gamma)/m;       
	return (-G*M/R**2 + cte*pow(r,2-3*gamma));
}

