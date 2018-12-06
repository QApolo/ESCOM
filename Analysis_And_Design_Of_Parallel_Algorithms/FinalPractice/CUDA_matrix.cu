#include <stdio.h>
#include <stdlib.h>

typedef int* Vector;

int techo(int tam, int block_size)
{
	return (tam / block_size) + (tam % block_size == 0? 0: 1);
}
__global__ void multiplicarMatrices(int *C, int *A, int *B, int tam)
{

	int idx = blockIdx.x * blockDim.x + threadIdx.x;
	int idy = blockIdx.y * blockDim.y + threadIdx.y;
	int index = idy * tam + idx;
	
	if(idy < tam && idx < tam)
	{
		int suma = 0;
		for(int k = 0; k < tam; k++)
			suma += A[idy + tam + k] * B [k * tam + idx];
		C[index] = suma;
	}
}

__global__ void sumarMatrices(int *C, int *A, int *B, int tam)
{

        int idx = blockIdx.x * blockDim.x + threadIdx.x;
        int idy = blockIdx.y * blockDim.y + threadIdx.y;
        int index = idy * tam + idx;

        if(idy < tam && idx < tam)
            C[index] = A[index] + B[index];
}


void imprimirMatriz(int *A, int tam)
{
	for(int i = 0; i < tam; i++)
	{
		for(int j = 0; j < tam; j++)
		{
			printf("%d ", A[tam * i + j]);
		}
		printf("\n");
	}
}
Vector newMatrizVectorizada(int tam, int val)
{
	Vector v = (Vector) malloc(sizeof(int) * tam * tam);
	for(int i = 0; i < tam; i++)
	{
		for(int j = 0; j < tam; j++)
		{
			v[i * tam + j] = val;
		}
	}
	return v;
}
int main(int argc, char **argv)
{
	Vector A_h, B_h, C_h;
	Vector A_d, B_d, C_d;
	
	int tam = 12;
	if(argc > 1)
		tam = atoi(argv[1]);
	int N = tam * tam;
	
	size_t  size = N * sizeof(int);
	
	A_h = newMatrizVectorizada(tam, 2);
	B_h = newMatrizVectorizada(tam, 3);
	C_h = newMatrizVectorizada(tam, 0);
	
	cudaMalloc((void**) &A_d, size);
	cudaMalloc((void**) &B_d, size);
	cudaMalloc((void**) &C_d, size);
	
	cudaMemcpy(A_d, A_h, size, cudaMemcpyHostToDevice);
	cudaMemcpy(B_d,	B_h, size, cudaMemcpyHostToDevice);
	
	int BLOCK_SIZE = 4;
	dim3 block_size(BLOCK_SIZE, BLOCK_SIZE);
	dim3 n_blocks(techo(tam, block_size.x), techo(tam, block_size.y));
	
	multiplicarMatrices<<< n_blocks, block_size >>> (C_d, A_d, B_d, tam);
	
	cudaMemcpy(C_h, C_d, size, cudaMemcpyDeviceToHost);

	imprimirMatriz(C_h, tam); 

	sumarMatrices <<< n_blocks, block_size>>> (C_d, A_d, B_d, tam);
	cudaMemcpy(C_h, C_d, size, cudaMemcpyDeviceToHost);
	printf("==============================================RESULTADO============================================\n");
	imprimirMatriz(C_h, tam);
	printf("===================================================================================================\n");
	
	free(A_h);
	free(B_h);
	free(C_h);

	cudaFree(A_d);
	cudaFree(B_d);
	cudaFree(C_d);

	return 0;
	
}
