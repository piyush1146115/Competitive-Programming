#include<bits/stdc++.h>
using namespace std;
//#define mod (1 << 64)

struct matrix {
  unsigned long long v[5][5];
  int row, col; // number of row and column
};


// multiplies two matrices and returns the result
matrix multiply(matrix a, matrix b) {
  assert(a.col == b.row);
  matrix r;
  r.row = a.row;
  r.col = b.col;
  for (int i = 0; i < r.row; i++) {
    for (int j = 0; j < r.col; j++) {
      unsigned long long  sum = 0;
      for (int k = 0; k < a.col;  k++) {
        sum += a.v[i][k] * b.v[k][j];
        //sum %= mod;
      }
      r.v[i][j] = sum;
    }
  }
  return r;
}

// returns mat^p 

matrix power(matrix mat, unsigned long long int p) {
  assert(p >= 1);
  if (p == 1) return mat;
  if (p % 2 == 1) 
    return multiply(mat, power(mat, p - 1));
  matrix ret = power(mat, p / 2);
  ret = multiply(ret, ret);
  return ret;
}

int main() {
  int test;
  unsigned long long int p, q, n;
	
	scanf("%d",&test);
  
  for(int tc = 1; tc <= test; tc++){
	  
    // input rout`ine
    scanf("%lld %lld %lld",&p, &q ,&n);
    
    // preparing the matrix
    matrix mat;
    mat.row = mat.col = 2;
    
   for(int i = 0; i < mat.row; i++){
	   for(int j = 0; j < mat.col; j++){
		   mat.v[i][j] = 0;
	   }
   }
   
   mat.v[0][0] = p;
   mat.v[0][1] = -q;
   mat.v[1][0] = 1;   

	//cout << "Case " << tc << ": ";
	
	printf("Case %d: ",tc);
	unsigned long long f2 = (p * p) - 2*q;
    
    if (n == 0) {
      //cout << 0 << endl;
      printf("2\n");
    }
    else if(n == 1){
		printf("%llu\n",p);
	}
	else if(n == 2){
		printf("%llu\n",f2);
	}
     else { 
      mat = power(mat, n - 1);
      //cout << mat.v[0][0] << " " << mat.v[0][1] << endl;
      
      unsigned long long ans =    (p * mat.v[0][0]) +  (2 *  mat.v[0][1]);
      //ans %= mod;
      printf("%llu\n",ans);
    }
  }
  return 0;
}
