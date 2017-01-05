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
    }
  }

  for (i = 0; i < m; i++) {
    for (j = 0; j < n; j++) {
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
  // Coding without blocking, there are different combinations to perform the loop.
  int i, j, l;
  for (i = 0; i < m; i++) {
    for (j = 0; j < n; j++) {
      C[i][j]=0;
    }
  }

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

void matmult_nat(int m,int n,int k,double **A,double **B,double **C){
  // Coding without blocking, there are different combinations to perform the loop.
  //printf("matmult_nat: m=%i, n=%i, k=%i\n", m, n, k);
  matmult_mnk(m,n,k,A,B,C);
}

void matmult_blk(int m,int n,int k,double **A,double **B,double **C){
  //printf("matmult_blk: m=%i, n=%i, k=%i\n", m, n, k);
  int i, j, l;
  const int blockSize = 4;
  for (i = 0; i < m; i++) {
    for (j = 0; j < n; j++) {
      C[i][j]=0;
    }
  }

  for (i = 0; i < m; i++) {
    for (j = 0; j < n; j++) {
      for (l = 0; l < k - (k%blockSize) ; l+= blockSize) {
	C[i][j] = C[i][j] + A[i][l]*B[l][j];
	C[i][j] = C[i][j] + A[i][l+1]*B[l+1][j];
	C[i][j] = C[i][j] + A[i][l+2]*B[l+2][j];
	C[i][j] = C[i][j] + A[i][l+3]*B[l+3][j];
      }
      
      if(k % blockSize > 0) {
        for (l = k - (k % blockSize); l < k; l++) {
	  C[i][j] = C[i][j] + A[i][l]*B[l][j];
        }
      }
    }
  }
}
