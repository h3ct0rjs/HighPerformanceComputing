#include <stdio.h>
#include <stdlib.h> 


//stored in the global memory 
//int rows=4, cols=4;
#define rows 2
#define cols 2 
//store in the stack
//use gdb to check this.
int i,j;
int **matrix;	// we need a double pointer, 
// a matrix is a vector of vectors

int main(){
//store in stack
	int x ; // just testing gdb as debuger
	//I allocate a simple row
	matrix =(int**)calloc(rows,sizeof(int*));	
	//then I iterate over it, to allocate the cols.
	for(i=0; i<rows;i++)
		matrix[i] = (int**)calloc(cols,sizeof(int*));
	printf("Ingresa los datos de la matrix\n");

	for(i=0;i<rows;i++){
		for(j=0;j<cols;j++){
			printf("%d ",matrix[i][j]);
		}
		printf("\n");
	}


	for(i=0;i<rows;i++){
		for(j=0;j<cols;j++){
			scanf("%d",&matrix[i][j]);
		}
	}

for(i=0;i<rows;i++){
		for(j=0;j<cols;j++){
			printf("%d ",matrix[i][j]);
		}
		printf("\n");
	}


	return  0
;}