#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
//High Performance Computing
//Lab#1: Matrix Multiplication 
//hfjimenez@utp.edu.co, 2017-2

//Strings label :
//[!]:Warning,Exit Process.
//[*]:Information interesting
//[Ok]: Process Completed 
//References:
//[1]https://linux.die.net/man/3/calloc

//A*B = C, representation of all the matrix
float **MatA, **MatB, **MatC;     //Heap MemStorage
int i,j,k;                        //global Mem

//My Function helpers
void printmat(float **Mat,int r, int  c);
void title(void);

#define version  "v0.1"
//First Time Using Colors Hooray
#define RES  "\x1B[0m"
#define RED  "\x1B[31m"
#define GRN  "\x1B[32m"
#define YEL  "\x1B[33m"
#define BLU  "\x1B[34m"
#define MAG  "\x1B[35m"
#define CYN  "\x1B[36m"
#define WHT  "\x1B[37m"

int main(int argc, const char * argv[])
{
  title();
  //File pointers,in read mode
  FILE *archi;
  FILE *archi2;
  FILE *result;
  int rows1,cols1,rows2,cols2;
  int sum=0;
  archi = fopen(argv[1],"r");
  archi2 = fopen(argv[2],"r");
  //NULL in C is ugly, NULL is equal to 0, not like in C++ <3 that is a real null value.
  if (archi == NULL || archi2 == NULL){       
    printf("%s[!]%s Imposible abrir los archivos pasados como argumentos\n",RED,RES);
    exit(0);
  }

  /*  int opts[4];            //to store the values.
    for(i=0; i<2; i++){
      fscanf(archi,"%d",&opts[i]);  //read the amount of rows and cols 
      fscanf(archi2,"%d",&opts[i+2]);   //read the amount of rows and cols 
    }

    //fclose(archi);            //Because I was having a trouble dealing with this,
    //fclose(archi2);           //I need to reopen the file using another bar. I try to figured it out with 
                                // with gdb and it seems that had something to do with a program that I use to 
                               // chroot process. Investigating about this.
  */

  //previous version has conflict with the pointer movmnt.
  fscanf(archi,"%i",&rows1);
  fscanf(archi,"%i",&cols1);
  fscanf(archi2,"%i",&rows2);
  fscanf(archi2,"%i",&cols2);

  printf("%s**Dimensiones Matriz**%s",CYN, RES);
  printf("\n%s[*]%s Matriz **A** Filas:%d Columnas:%d",YEL,RES,rows1,cols1);
  printf("\n%s[*]%s Matriz **B** Filas:%d Columnas:%d",YEL,RES,rows2,cols2);
  
  if(cols1!=rows2){
    printf("\n%s[!]%s No Es Posible realizar la Multiplicacion entre Matrices\n ",RED,RES);
    printf("%s[NOTA:!]%s Dimensiones Incompatibles,saliendo...\n",RED,RES );
    exit(0);
  }

  //Allocate memory for the Matrices, with initilize values to cero. 
  //avoid the for loops to init the matriz values in 0.see[1] for more info
  
  float **MatA = (float **)calloc(rows1,sizeof(float*));
  for(i = 0; i < rows1; i++)
      MatA[i] = (float *)calloc(cols1 ,sizeof(float));
  
  float **MatB = (float **)calloc(rows2, sizeof(float*));
  for(i = 0; i < rows2; i++)
      MatB[i] = (float *)calloc(cols2, sizeof(float));

  float **MatC = (float **)calloc(rows1, sizeof(float*));
  for(i = 0; i < rows1; i++)
      MatC[i] = (float *)calloc(cols2, sizeof(float));

  if (!MatA || !MatB || !MatC) { 
      printf("\n%s[!]%s Falla de Reserva de Memoria",RED,RES);
      exit(ENOMEM);}
  
  printf("\n%s[*]%s Leyendo Valores de la Matriz A en el archivos\n",YEL, RES);
  while(!feof(archi)){
    for(i=0;i<rows1;i++){
      for(j=0;j<cols1;j++){
        fscanf(archi,"%f",&MatA[i][j]);
        }
      }
    }
  printf("%s[*]%s Leyendo Valores de la Matriz B en el archivos\n",YEL, RES);
  while(!feof(archi2)){
    for(i=0;i<rows2;i++){
      for(j=0;j<cols2;j++){
        fscanf(archi2,"%f",&MatB[i][j]);
      }
    }
  }
 
  printmat(MatA,rows1,cols1);
  printmat(MatB,rows2,cols2);
  printf("%s[*]%s Multiplicando Matriz:\n",YEL, RES);
  multimat(MatA,MatB,MatC,rows1,rows2,cols2);
  printmat(MatC,rows1,cols2);
  result = fopen("r.txt","w");
  if (result == NULL){       
    printf("%s [!]%s Imposible abrir el archivo para los resultados\n",RED,RES);
    exit(0);
  }

  for(i=0;i<rows2;i++){
    for(j=0;j<cols2;j++){
      fprintf(result,"%.2f ",MatB[i][j]);
    }
    fprintf(result,"\n");
  }

  //free up memory
  free(*MatA);
  free(*MatB);
  free(*MatC);
  free(MatA);
  free(MatB);
  free(MatC);
  
  fclose(archi);
  fclose(archi2);
  fclose(result);
}

void multimat(float** M,float** M2,float**R,int r1,int r2,int c2){
  int tmp=0; 
  for(int i=0;i<r1;i++){
    for(int j=0;j<c2;j++){
      tmp=0;
      for(int k=0;k<r2;k++){
        tmp+=M[i][k]*M2[k][j];
      }
     R[i][j]=tmp;
    } 
  }
} 


void printmat(float **Mat,int r,int c){
  printf("\nMatriz\n%s---%s\n",BLU,RES );
  for(i=0;i<r;i++){
      for(j=0;j<c;j++)
        printf("%.2f  ",Mat[i][j]);
      printf("\n");
  }

}

void title(void){
printf("        :::    ::: :::::::::   :::::::: \n");
printf("     :+:    :+: :+:    :+: :+:    :+: \n");
printf("    +:+    +:+ +:+    +:+ +:+         \n");
printf("   +#++:++#++ +#++:++#+  +#+          \n");
printf("  +#+    +#+ +#+        +#+           \n");
printf(" #+#    #+# #+#        #+#    #+#     \n");
printf("###    ### ###         ########       \n\n");
  printf("%s-----------------------------%s\n",BLU,RES);
  printf("%sMultiplicacion de Matrices\nhfjimenez@utp.edu.co,2017-2\n\tH.P.C%s\n",RED,RES);
  printf("%s-----------------------------\n%s",BLU,RES);
}