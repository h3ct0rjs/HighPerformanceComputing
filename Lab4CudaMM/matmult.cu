#include <stdio.h>
#include <time.h>
#define N 1024

__global__ void Matriz_GPU_Mult(int *a, int *b, int *c) {
	int k, sum = 0;
	int i = blockIdx.x * blockDim.x + threadIdx.x; 
  int j = blockIdx.y * blockDim.y + threadIdx.y;
  if (i < N && j < N) {
    for (k = 0; k < N; k++) {
      sum += a[j * N + k] * b[k * N + i];
    }
    c[j * N + i] = sum;
  }
}

int main() {
  double timeGPU;
  int h_A[N][N], h_B[N][N], h_C[N][N];
  int *d_a, *d_b, *d_c;
  
  cudaMalloc((void **) &d_a, N*sizeof(int));
  cudaMalloc((void **) &d_b, N*sizeof(int));
  cudaMalloc((void **) &d_c, N*sizeof(int));

  cudaMemcpy(d_a, A, size, cudaMemcpyHostToDevice);
  cudaMemcpy(d_b, B, size, cudaMemcpyHostToDevice);

  //int threadsPerBlock(16);
  //int numBlocks(N/threadsPerBlock);
  dim3 threadsPerBlock(32, 32);
  dim3 numBlocks(N/threadsPerBlock.x, N/threadsPerBlock.y);
  clock_t startGPU  = clock();
  Matriz_GPU_Mult<<<numBlocks, threadsPerBlock>>>(d_a, d_b, d_c);
	timeGPU = ((double)(clock() - startGPU))/CLOCKS_PER_SEC;
  cudaMemcpy(C, d_c, size, cudaMemcpyDeviceToHost);
  cudaFree(d_a);
  cudaFree(d_b);
  cudaFree(d_c);
  // tiempos de ejecucion
  printf("tiempo GPU = %f s",timeGPU);
  return 0;
}
