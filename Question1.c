#include <stdio.h>
#include <time.h>

int MIN(int a, int b) {
  if(a < b) { return a; }
  return b;
}
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

void matmult_blk(int m,int n,int k, double **A,double **B,double **C, int bs){
  //printf("matmult_blk: m=%i, n=%i, k=%i\n, bs=%i", m, n, k, bs);
  //order is actually int1, int3, int2
  int i, j, l, i2, j2, l2;
  int ie = 0;
  int je = 0;
  int ke = 0;

  if(m % bs != 0) { ie = 1; }
  if(n % bs != 0) { je = 1; }
  if(k % bs != 0) { ke = 1; }
  
  for (i = 0; i < m; i++) {
    for (j = 0; j < n; j++) {
      C[i][j]=0;
    }
  }

  for (i = 0; i < m/bs + ie; i++) { 
    for (j = 0; j < n/bs + je; j++) {   
      for (l = 0; l < k/bs + ke; l++) {
        for(i2 = i*bs; i2 < MIN((i+1)*bs, m); i2++) { 
          for(j2 = j*bs; j2 < MIN((j+1)*bs, n); j2++) {     
            for(l2 = l*bs; l2 < MIN((l+1)*bs, k); l2++) {
	      C[i2][j2] = C[i2][j2] + A[i2][l2]*B[l2][j2];
            }
          }  
        }
      }
    }
  }
  /*
  i2 = 0; 
  j2 = 0;
  int b1, b2;
  for (l = 0; l < (k/bs + ke); l++) {
    for (l2 = 0; l2 < (k/bs + ke); l2++) {
      for (b1 = 0; b1 < bs; b1++) {
        for(b2 = 0; b2 < bs; b2++) {
          C[i2][j2] = C[i2][j2] + A[i2][b2]*B[b2][j2]; 
        }
        i2++;
        j2++;
      }
    

  for (i = 0; i < m/bs + ie; i++) {
    for(i2 = i*bs; i2 < MIN((i+1)*bs, m); i2++) {

    for (j = 0; j < n/bs + je; j++) { 
    for(l2 = l*bs; l2 < MIN((l+1)*bs, k); l2++) {
         
             
          for(j2 = j*bs; j2 < MIN((j+1)*bs, n); j2++) {     
  }
  */
}
