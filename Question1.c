#include <stdio.h>
#include <time.h>

//QUESTION2
//OP1
void matmult_mnk(int m,int n,int k,double **A,double **B,double **C){
  // Coding without blocking, there are different combinations to perform the loop.
  int i, j, l;
  for (i = 0; i < m; i++) {
    for (j = 0; j < n; j++) {
      C[i][j]=0;
      for (l = 0; l < k; l++) {
	C[i][j] = C[i][j] + A[i][l]*B[l][j];
      }
    }
  }
}
//OP2
void matmult_mkn(int m,int n,int k,double **A,double **B,double **C){
  // Coding without blocking, there are different combinations to perform the loop.
  int i, j, l;
  printf("matmult_mkn: before first loop\n");
  for (i = 0; i < m; i++) {
    printf("i=%i\n", i);
    for (j = 0; j < n; j++) {
      printf("j=%i\n", j);
      C[i][l]=0;
      printf("hola\n");
      for (l = 0; l < k; l++) {
        printf("l=%i\n", l);
	C[i][l] = C[i][l] + A[i][j]*B[j][l];
      }
    }
  }
}

//OP3
void matmult_nmk(int m,int n,int k,double **A,double **B,double **C){
  // Coding without blocking, there are different combinations to perform the loop.
  int i, j, l;
  for (i = 0; i < n; i++) {
    for (j = 0; j < m; j++) {
      C[j][i]=0;
      for (l = 0; l < k; l++) {
	C[j][i] = C[j][i] + A[j][l]*B[l][i];
      }
    }
  }
}

//OP4
void matmult_nkm(int m,int n,int k,double **A,double **B,double **C){
  // Coding without blocking, there are different combinations to perform the loop.
  int i, j, l;
  for (i = 0; i < n; i++) {
    for (j = 0; j < k; j++) {
      C[l][i]=0;
      for (l = 0; l < m; l++) {
	C[l][i] = C[l][i] + A[l][j]*B[j][i];
      }
    }
  }
}

//OP5
void matmult_kmn(int m,int n,int k,double **A,double **B,double **C){
  // Coding without blocking, there are different combinations to perform the loop.
  int i, j, l;
  for (i = 0; i < k; i++) {
    for (j = 0; j < m; j++) {
      C[j][l]=0;
      for (l = 0; l < n; l++) {
	C[j][l] = C[j][l] + A[j][i]*B[i][l];
      }
    }
  }
}

//OP6
void matmult_knm(int m,int n,int k,double **A,double **B,double **C){
  // Coding without blocking, there are different combinations to perform the loop.
  int i, j, l;
  for (i = 0; i < k; i++) {
    for (j = 0; j < n; j++) {
      C[l][j]=0;
      for (l = 0; l < m; l++) {
	C[l][j] = C[l][j] + A[l][i]*B[i][j];
      }
    }
  }
}

void matmult_nat(int m,int n,int k,double **A,double **B,double **C){
  // Coding without blocking, there are different combinations to perform the loop.
  /*
  int i, j, l;
  for (i = 0; i < m; i++) {
    for (j = 0; j < n; j++) {
      C[i][j]=0;
      for (l = 0; l < k; l++) {
	C[i][j] = C[i][j] + A[i][l]*B[l][j];
      }
    }
    }*/
  printf("before running function\n");
  matmult_mkn(m,n,k,A,B,C);
}
