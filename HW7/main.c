﻿// Universidad de los Andes
// Física computacional
// Tarea 7
// Archivo con el programa principal
// Autores:
//	Andrés Felipe García Albarracín
//	Andrea Rozo Méndez

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include "functions.h"
#include "slopes.h"
#include <time.h>

#define tInicial 0.0
#define tFinal 1500
#define R0 1.7 // [r]
#define v0 0 // [cm/s]
#define P0 5.6e-6 // [m/r*t**2]

int main()
{
	int i;
	double h = 1;
	int n_points = tFinal/h;
	double *t = malloc(n_points*sizeof(double));
	double *r = malloc(n_points*sizeof(double));
	double *v = malloc(n_points*sizeof(double));
	double *p = malloc(n_points*sizeof(double));
	double *k1 = malloc(2*sizeof(double));
	double *k2 = malloc(2*sizeof(double));
	double *k3 = malloc(2*sizeof(double));
	double *k4 = malloc(2*sizeof(double));
	double *slope = malloc(2*sizeof(double));
	FILE 	*fileOut;
	FILE	*fileGrap;
	srand48 (time(NULL));

	if(!t || !r || !v || !k1 || !k2 || !k3 || !k4 || !p)
	{
		printf("Problema creando alguno de los arreglos");
		exit(1);
	}
	
	// Condiciones iniciales
	r[0] = R0;
	v[0] = v0;
	p[0] = P0;

	char nombreArchivo[256] = "fileOut";
	strcat(nombreArchivo,".txt");
	
	fileOut = fopen(nombreArchivo,"w");
	fprintf(fileOut, "%f	%f	%f	%f\n", t[0], r[0], v[0],p[0]);

	for (i=1; i<n_points; i++)
	{
		t[i] = i*h + tInicial;		
		slopeRV(t[i-1], r[i-1], v[i-1], h, k1, k2, k3, k4, slope);
		r[i] = r[i-1] + h*slope[0];
		v[i] = v[i-1] + h*slope[1];
		p[i] = P0*pow(R0,5.0)/(r[i]*r[i]*r[i]*r[i]*r[i]);
		fprintf(fileOut, "%f	%f	%f	%f\n", t[i], r[i], v[i], p[i]);
	}


	fclose(fileOut);	
		
	return 0;

}
