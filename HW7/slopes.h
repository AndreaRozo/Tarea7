// Universidad de los Andes
// Física computacional
// Tarea 6
// Archivo con el cálculo de las pendientes
// Autores:
//	Andrés Felipe García Albarracín
//	Andrea Rozo

/**
* Calcula los coeficientes de las pendientes k1, k2, k3 y k4
*/
void calK(double t, double x, double y, double z, double h, double *k1, double *k2, double *k3, double *k4);

/**
* Calcula el vector de pendientes
*/
double slopeXYZ(double t, double x, double y, double z, double h, double *k1, double *k2, double *k3, double *k4, double *slope);
