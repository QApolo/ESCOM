#include <stdio.h>
#include <math.h>
#include <time.h>
#include <stdlib.h>

struct Punto
{
	double x;
	double y;
};
typedef struct Punto Punto;

Punto generarPunto()
{
	Punto p1;
	p1.x = rand()/(double)RAND_MAX;
	p1.y = rand()/(double)RAND_MAX;
	return p1;
}
double getModulo(Punto a)
{
	return sqrt(pow(a.x,2) + pow(a.y,2));
}
double getPiValue(long long *n)
{
	long long i;
	Punto p1;
	double cuentaAreaCirculo = 0.0, cuentaAreaCuadrado = 0.0;
	
	printf("Generando valor de PI...\n");
	#pragma omp num_threads(4)
	#pragma omp for
		for(i = 0; i <= *n; i++)
		{
			p1 = generarPunto(); 	//printf("%f %f\n", p1.x, p1.y);
			if(getModulo(p1) <= 1.0) cuentaAreaCirculo++;
			else cuentaAreaCuadrado++;	
		}
	
	//printf("Area Circulo: %f\nArea Cuadrado: %f\n", cuentaAreaCirculo,cuentaAreaCuadrado);
	return (4.0 * cuentaAreaCirculo / (cuentaAreaCuadrado + cuentaAreaCirculo));

}
int main(int argc, char **argv)
{	
	srand(time(NULL));
	long long n = 1e8;
	if(argc > 1)
		n = atoi(argv[1]);
	printf("%f\n",getPiValue(&n) );
	return 0;
}