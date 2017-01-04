#include <stdio.h>
#include <time.h>

//int add (int i, int j){
//return i+j;
//}


// QUESTION1
void matmult_nat(int m,int n,int k,double **A,double **B,double **C){
  // Coding without blocking, there are different combinations to perform the loop.
  int i, j, l;
  for (i = 0; i < m; i++) {
    // printf (i);
    for (j = 0; j < n; j++) {
      //printf (j);
      C[i][j]=0;
      for (l = 0; l < k; l++) {
	//printf (l);
	C[i][j] = C[i][j] + A[i][l]*B[l][j];
      }
    }
  }
}


