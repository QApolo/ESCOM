#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
#include <math.h>

int TAMSQ = 1000;
typedef short Tipo;
typedef Tipo** Matriz;

Matriz newMatriz(Tipo);
Matriz getSuma(Matriz, Matriz);
void imprimirMatriz(Matriz);

Matriz newMatriz(Tipo val)
{
	Matriz matriz = (Tipo**)malloc(sizeof(Tipo*) * TAMSQ);
	int i, j = 0;
	#pragma OMP parallel for num_threads(100) private(j)
	{
		for(i = 0; i < TAMSQ; i++)
		{
			matriz[i] = (Tipo*) malloc(sizeof(Tipo) * TAMSQ);
			for(j = 0; j < TAMSQ; j++)
				matriz[i][j] = val;
		}
	}
	return matriz;
} 

Matriz getSuma(Matriz A, Matriz B)
{
	Matriz C = newMatriz(0);
	int i, j;
	#pragma OMP parallel for num_threads(omp_get_max_threads()) private(j)
	{
		for(i = 0; i < TAMSQ; i++)
		{
			for(j = 0; j < TAMSQ; j++)
				C[i][j] = A[i][j] + B[i][j];
		}
	}
	return C;
}
Matriz getProducto(Matriz A, Matriz B)
{
	Matriz C = newMatriz(0);
	int i, j, k;
	#pragma OMP parallel for num_threads(omp_get_max_threads()) private(j, k) 
	{
		for(i = 0; i < TAMSQ; i++)
		{
			for(j = 0; j < TAMSQ; j++)
			{
				Tipo suma = 0;
				for(k = 0; k < TAMSQ; k++)
					suma += (A[i][k] * B[k][j]);
				C[i][j] = suma;
			}
		}
	}
	return C;	
}
void imprimirMatriz(Matriz A)
{
	int i, j;
	for(i = 0; i < TAMSQ; i++)
	{
		for(j = 0; j < TAMSQ; j++)
			printf("%d ", A[i][j]);
		printf("\n");
	}
}
int main(int argc, char **argv)
{
	//omp_set_dynamic(0);
	//printf("%d\n",omp_get_max_threads());
	if(argc > 1)
		TAMSQ = atoi(argv[1]);
	printf("Tamaño Matriz (%d ,%d)\n", TAMSQ, TAMSQ);
	int i, j;
	Matriz A = newMatriz(2);
	Matriz B = newMatriz(3);
	Matriz C;

	if(TAMSQ <= 35)
	{
		printf("Matriz A:\n\n");
		imprimirMatriz(A);
		printf("\nMatriz B\n\n");
		imprimirMatriz(B);
		printf("\n");
	}
	short op = 0;
	printf("Seleccione opcion: \n 1) Suma\n 2) Multiplicacion\n");
	scanf("%hu", &op);
	if(op == 2)
		C = getProducto(A, B);
	else C = getSuma(A, B);

	if(TAMSQ <= 35)
	{
		printf("========================RESULTADO=================\n");

		imprimirMatriz(C);
		printf("==================================================\n");
	}
	printf("finalizado\n");
	
	for(int i = 0; i < sqrt(TAMSQ); i++)
	{
		free(A[i]);
		free(B[i]);
	}
	free(A);
	free(B);

	return 0;
}
