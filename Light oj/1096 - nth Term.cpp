#include<bits/stdc++.h>
using namespace std;
#define mod 10007

struct matrix {
  int v[5][5];
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
      int sum = 0;
      for (int k = 0; k < a.col;  k++) {
        sum += a.v[i][k] * b.v[k][j];
        sum %= mod;
      }
      r.v[i][j] = sum;
    }
  }
  return r;
}

// returns mat^p 

matrix power(matrix mat, long long int p) {
  assert(p >= 1);
  if (p == 1) return mat;
  if (p % 2 == 1) 
    return multiply(mat, power(mat, p - 1));
  matrix ret = power(mat, p / 2);
  ret = multiply(ret, ret);
  return ret;
}

int main() {
  int tcase;
  long long int a, b, n, m, c;

  cin >> tcase;
  for(int tc = 1; tc <= tcase; tc++){
	  
    // input routine
    cin >> n >> a >> b >> c;
    
    // preparing the matrix
    matrix mat;
    mat.row = mat.col = 4;
    
   for(int i = 0; i < mat.row; i++){
	   for(int j = 0; j < mat.col; j++){
		   mat.v[i][j] = 0;
	   }
   }
   
   mat.v[0][0] = a;
   mat.v[0][2] = b;
   mat.v[0][3]  = mat.v[1][0] = mat.v[2][1] = mat.v[3][3] = 1;
   

	cout << "Case " << tc << ": ";
    if (n < 3) {
      cout << 0 << endl;
    }
     else { 
      mat = power(mat, n - 2);
      long long ans =  c*mat.v[0][3];
      ans %= mod;
      cout << ans << endl;
    }
  }
  return 0;
}
