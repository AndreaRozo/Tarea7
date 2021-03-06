// Universidad de los Andes
// Física computacional
// Tarea 7
// Archivo con el cálculo de las pendientes
// Autores:
//	Andrés Felipe García Albarracín
//	Andrea Rozo

/**
* Calcula los coeficientes de las pendientes k1, k2, k3 y k4
*/
void calK(double t, double r, double v, double h, double *k1, double *k2, double *k3, double *k4);

/**
* Calcula el vector de pendientes
*/
double slopeRV(double t, double r, double v, double h, double *k1, double *k2, double *k3, double *k4, double *slope);
