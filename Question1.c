#include <stdio.h>
#include <time.h>
#include <time.h>
#include <cblas.h>

#define MIN(a,b) ((a) < (b) ? a : b)

//QUESTION2
//OP1

//OP2
void matmult_mkn(int m,int n,int k,double **A,double **B,double **C){
  // Coding without blocking, there are different combinations to perform the loop.
  int i, j, l;
  for (i = 0; i < m; i++) {
    for (j = 0; j < n; j++) {
      C[i][j]=0;
    }
  }

  for (i = 0; i < m; i++) {
    for (l = 0; l < k; l++) {
      for (j = 0; j < n; j++) {
        C[i][j] = C[i][j] + A[i][l]*B[l][j];
      }
    }
  }
}

//OP3
void matmult_nmk(int m,int n,int k,double **A,double **B,double **C){
  // Coding without blocking, there are different combinations to perform the loop.
  int i, j, l;
  for (i = 0; i < m; i++) {
    for (j = 0; j < n; j++) {
      C[i][j]=0;
    }
  }

  for (j = 0; j < n; j++) {
    for (i = 0; i < m; i++) {
      for (l = 0; l < k; l++) {
        C[i][j] = C[i][j] + A[i][l]*B[l][j];
      }
    }
  }
}

//OP4
void matmult_nkm(int m,int n,int k,double **A,double **B,double **C){
  // C initialization.
  int i, j, l;
  for (i = 0; i < m; i++) {
    for (j = 0; j < n; j++) {
      C[i][j]=0;
    }
  }
  // Main code
  for (j = 0; j < n; j++) {
    for (l = 0; l < k; l++) {
      for (i = 0; i < m; i++) {
        C[i][j] = C[i][j] + A[i][l]*B[l][j];
      }
    }
  }
}

//OP5
void matmult_kmn(int m,int n,int k,double **A,double **B,double **C){
  // Coding without blocking, there are different combinations to perform the loop.
  int i, j, l;
  for (i = 0; i < m; i++) {
    for (j = 0; j < n; j++) {
      C[i][j]=0;
    }
  }
  
  for (l = 0; l < k; l++) {
    for (i = 0; i < m; i++) {
      for (j = 0; j < n; j++) {
        C[i][j] = C[i][j] + A[i][l]*B[l][j];
      }
    }
  } 
}

//OP6
void matmult_knm(int m,int n,int k,double **A,double **B,double **C){
  // Coding without blocking, there are different combinations to perform the loop.
  int i, j, l;
  for (i = 0; i < m; i++) {
    for (j = 0; j < n; j++) {
      C[i][j]=0;
    }
  }
  
  for (l = 0; l < k; l++) {
    for (j = 0; j < n; j++) {
      for (i = 0; i < m; i++) {    
        C[i][j] = C[i][j] + A[i][l]*B[l][j];     
      }
    }
  } 
}

void matmult_mnk(int m,int n,int k,double **A,double **B,double **C){.
  int i, j, l;
  // C initialization
  for (i = 0; i < m; i++) {
    for (j = 0; j < n; j++) {
      C[i][j]=0;
    }
  }
  //main code
  for (i = 0; i < m; i++) {
    for (j = 0; j < n; j++) {
      for (l = 0; l < k; l++) {
	C[i][j] += A[i][l]*B[l][j];
      }
    }
  }
}

void matmult_nat(int m,int n,int k,double **A,double **B,double **C){
  //Calling the function above.
  matmult_mnk(m,n,k,A,B,C);
}

void matmult_lib(int m, int n, int k, double **A, double **B, double **C) {
	cblas_dgemm(CblasRowMajor, CblasNoTrans, CblasNoTrans, m, n, k, 1, *A, k, *B, n, 0, *C, n);
}
void matmult_blk(int m,int n,int k, double **A,double **B,double **C, int bs){
  int i1, j1, l1, i2, j2, l2, i, j;
  
  for (i = 0; i < m; i++) {
    for (j = 0; j < n; j++) {
      C[i][j]=0;
    }
  }

  for (i1= 0;i1<m; i1+=bs) { 
    for (j1 = 0; j1 < n; j1+=bs) {   
      for (l1 = 0; l1 < k; l1+=bs) {
	int test1 = MIN(m-i1, bs);
	int test2 = MIN (n- j1, bs);
	int test3 = MIN(k-l1, bs);
        for(i2 = 0; i2 < test1; i2++) { 
          for(j2 = 0; j2 < test2; j2++) {     
            for(l2 = 0; l2 < test3; l2++) {
	      C[i1+i2][j1+j2] += A[i1+i2][l1+l2]*B[l1+l2][j1+j2];
            }
          }  
        }
      }
    }
  }
}

//PROVE
void matmult_blk(int m,int n,int k, double **A,double **B,double **C, int bs){
  int i1, j1, l1, i2, j2, l2, i, j;
  
  for (i = 0; i < m; i++) {
    for (j = 0; j < n; j++) {
      C[i][j]=0;
    }
  }

  for (i1= 0;i1<m; i1+=bs) { 
    for (l1 = 0; l1 < k; l1+=bs) {
      for (j1 = 0; j1 < n; j1+=bs) {   
	int test1 = MIN(m-i1, bs);
	int test2 = MIN (n- j1, bs);
	int test3 = MIN(k-l1, bs);
        for(i2 = 0; i2 < test1; i2++) { 
	  for(l2 = 0; l2 < test3; l2++) {
	    for(j2 = 0; j2 < test2; j2++) {     
	      C[i1+i2][j1+j2] += A[i1+i2][l1+l2]*B[l1+l2][j1+j2];
            }
          }  
        }
      }
    }
  }
}

