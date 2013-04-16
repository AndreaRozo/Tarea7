// Universidad de los Andes
// Física computacional
// Tarea 6
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
#define tFinal 30.0

int main()
{
	int j;	
	int i;
	double h = 0.01;
	int n_points = tFinal/h;
	double *t = malloc(n_points*sizeof(double));
	double *r = malloc(n_points*sizeof(double));
	double *v = malloc(n_points*sizeof(double));
	double *k1 = malloc(2*sizeof(double));
	double *k2 = malloc(2*sizeof(double));
	double *k3 = malloc(2*sizeof(double));
	double *k4 = malloc(2*sizeof(double));
	double *slope = malloc(2*sizeof(double));
	FILE 	*fileOut;
	FILE	*fileGrap;
	srand48 (time(NULL));

	fileGrap = fopen("graphics.gp","w");
	fprintf(fileGrap, "set terminal jpeg\n");

	if(!t || !r || !v || !k1 || !k2 || !k3 || !k4)
	{
		printf("Problema creando alguno de los arreglos");
		exit(1);
	}
	
	for (j = 0; j<10; j++)
	{
		
		double Xini = drand48()*20-10;
		double Yini = drand48()*20-10;
		double Zini = drand48()*20-10;

		// Condiciones iniciales
		t[0] = tInicial;	
		x[0] = Xini;
		y[0] = Yini;
		z[0] = Zini;

		char nombreArchivo[256] = "fileOut";
		char num[5];
		sprintf(num,"%d",j);
		strcat(nombreArchivo,num);
		strcat(nombreArchivo,".txt");
		
		fileOut = fopen(nombreArchivo,"w");
		fprintf(fileOut, "%f	%f	%f	%f\n", t[0], x[0], y[0], z[0]);
	
		for (i=1; i<n_points; i++)
		{
			t[i] = i*h + tInicial;		
			slopeXYZ(t[i-1], x[i-1], y[i-1], z[i-1], h, k1, k2, k3, k4, slope);
			x[i] = x[i-1] + h*slope[0];
			y[i] = y[i-1] + h*slope[1];
			z[i] = z[i-1] + h*slope[2];
			fprintf(fileOut, "%f	%f	%f	%f\n", t[i], x[i], y[i], z[i]);
		}

		fprintf(fileGrap, "set output 'planoxy%d.jpg'\n",j);
		fprintf(fileGrap, "set title \"Plano x-y\"\n");
		fprintf(fileGrap, "set xlabel \"x\"\n");
		fprintf(fileGrap, "set ylabel \"y\"\n");
		fprintf(fileGrap, "plot 'fileOut%i.txt' using 2:3\n",j);

		fprintf(fileGrap, "set output 'planoxz%d.jpg'\n",j);
		fprintf(fileGrap, "set title \"Plano x-z\"\n");
		fprintf(fileGrap, "set xlabel \"x\"\n");
		fprintf(fileGrap, "set ylabel \"z\"\n");
		fprintf(fileGrap, "plot 'fileOut%i.txt' using 2:4\n",j);

		fprintf(fileGrap, "set output 'planoyz%d.jpg'\n",j);
		fprintf(fileGrap, "set title \"Plano y-z\"\n");
		fprintf(fileGrap, "set xlabel \"y\"\n");
		fprintf(fileGrap, "set ylabel \"z\"\n");
		fprintf(fileGrap, "plot 'fileOut%i.txt' using 3:4\n",j);

		fclose(fileOut);	
	}
	fclose(fileGrap);		
	return 0;

}
