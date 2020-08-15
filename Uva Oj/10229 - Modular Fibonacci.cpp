#include<bits/stdc++.h>
using namespace std;

struct matrix {
  long long int v[5][5];
  long long int row, col; // number of row and column
};
long long int mod;

// multiplies two matrices and returns the result
matrix multiply(matrix a, matrix b) {
  assert(a.col == b.row);
  matrix r;
  r.row = a.row;
  r.col = b.col;
  for (long long int i = 0; i < r.row; i++) {
    for (long long int j = 0; j < r.col; j++) {
      long long int sum = 0;
      for (long long int k = 0; k < a.col;  k++) {
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
  if(p == 1) return mat;
  if(p % 2 == 1)
    return multiply(mat, power(mat, p - 1));
  matrix ret = power(mat, p / 2);
  ret = multiply(ret, ret);
  return ret;
}

int main() {
  long long int  n, m;


  while(scanf("%lld %lld", &n, &m) == 2){
    // input routine

    // preparing the matrix
    matrix mat;
    mat.row = mat.col = 2;
    mat.v[0][0] = mat.v[0][1] = mat.v[1][0] = 1;
    mat.v[1][1] = 0;

    // preparing mod value
    mod = 1;
    for (int i = 0; i < m; i++) mod *= 2;


    if (n < 3) {
      if (n == 0) cout << 0 << endl;
      if (n == 1) cout << 1 << endl;
      if (n == 2) cout <<  1 << endl;
    }
     else {
      mat = power(mat, n - 2);

      long long int ans =  mat.v[0][0] +  mat.v[0][1];
      ans %= mod;
      cout << ans << endl;
    }
  }
  return 0;
}
