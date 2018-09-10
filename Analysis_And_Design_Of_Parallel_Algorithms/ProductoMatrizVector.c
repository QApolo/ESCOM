#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
typedef int Tipo;
typedef Tipo** Matriz;
typedef Tipo* Vector;
typedef int Bool;

int max_m = 10000, max_n = 100000;

#define TRUE 1
#define FALSE 0

Tipo *newVector(int n)
{
	Tipo *vec = (Tipo*)malloc(n*sizeof(Tipo));
	return vec;
}

Tipo **newMatriz(int m, int n)
{
	Tipo **matriz = (Tipo**)malloc(m * sizeof(Tipo*));
	int i;
	for(i = 0; i < m; i++)
		matriz[i] = (Tipo*)malloc(n * sizeof(Tipo));
	return matriz;
}
//tamano matriz: mxn, tamano vector r=n
Tipo *productoMatrizVector(Tipo **matriz, Tipo *vector, int m, int n, int r)
{
	if (r != n) return NULL;

	int i, j;
	Tipo res;
	
	Tipo *producto = newVector(m);
	omp_set_num_threads(4);
	#pragma omp parallel for private(i)
	for(i = 0; i < m; i++)
	{	res = 0;
		for(j = 0; j < n; j++)
			res += matriz[i][j] * vector[j];
		producto[i] = res;
	}
	return producto;
}
//precedencia: matriz, vector, m*n, r
void llenar(Matriz matriz, Vector vector,int m, int n,Bool random,Tipo val)
{
	if(matriz == NULL && vector == NULL) return;	
	int i,j;
	if(random == FALSE)
	{
		if(matriz == NULL )
			for(i = 0; i < n; i++)
				vector[i] = val;
		if(vector == NULL )
		{
			for(i = 0; i < m; i++)
				for(j = 0; j < n; j++)
					matriz[i][j] = val;
		}
	}
	else
	{
	
	}	
}
void print(Matriz matriz, Vector vector,int m, int n, int r)
{
	if(matriz == NULL && vector == NULL) return;
	int i, j;
	if(matriz == NULL)
	{
		for(i = 0; i < r; i++)
			printf("[%d]\n",vector[i]);
	}
	else if(vector == NULL)
	{
		for(i = 0; i < m; i++)
		{
			for(j = 0; j < n; j++)
				printf("%d ",matriz[i][j]);
		printf("\n");
		}
	}
}
int main()
{	
	Matriz matriz = newMatriz(max_m,max_n);
	Vector vector = newVector(max_n);
	llenar(matriz,NULL,max_m,max_n, FALSE,8);
	llenar(NULL,vector,1,max_n,FALSE,3);	
				
	//print(NULL,vector,0,0,max_n);
	//print(matriz,NULL,max_m, max_n,0);
	Vector producto = productoMatrizVector(matriz, vector, max_m,max_n,max_n);
	print(NULL, producto,0,0,max_m);
	
	return 0;
}
