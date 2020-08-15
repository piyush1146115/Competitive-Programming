#include<bits/stdc++.h>
using namespace std;
int mod;

struct matrix {
  int v[8][8];
  int row, col; // number of row and column

	void print(){
		
		for(int i=0;i<6;i++)
		{
					for(int j=0;j<6;j++)cout<<v[i][j]<<" ";
			cout<<endl;
		}
	}
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


int main()
{
	int test;
	scanf("%d", &test);
	
	for(int tc = 1; tc <= test; tc++){
	int a1, b1, c1, a2, b2, c2;
	int f0, f1, f2, g0, g1, g2;
	
	
		scanf("%d %d %d", &a1, &b1, &c1);
		scanf("%d %d %d",&a2, &b2, &c2);
		scanf("%d %d %d",&f0, &f1, &f2);
		scanf("%d %d %d", &g0, &g1, &g2);
	
	
	matrix mat;
    mat.row = mat.col = 6;
    
   for(int i = 0; i < mat.row; i++){
	   for(int j = 0; j < mat.col; j++){
		   mat.v[i][j] = 0;
	   }
   }
   
   mat.v[0][0] = a1;
   mat.v[0][1] = b1;
   mat.v[0][5] = c1;
   mat.v[1][0] = 1;
   mat.v[2][1] = 1;
   mat.v[4][3] = 1;
   mat.v[5][4] = 1;
   mat.v[3][2] = c2;
   mat.v[3][3] = a2;
   mat.v[3][4] = b2;
	
	
	scanf("%d", &mod);
	
	int q;
	scanf("%d", &q);
	printf("Case %d:\n", tc);
	
	while(q--){
		int n;
		scanf("%d",&n);
		if(n < 3){
			if(n == 0){
				printf("%d %d\n",f0 % mod, g0%mod);
			}
			else if(n == 1){
				printf("%d %d\n",f1 % mod, g1%mod);
			}
			if(n == 2){
				printf("%d %d\n",f2 % mod, g2%mod);
			}
		}
		else{
		matrix m = mat;
		m = power(m, n - 2);
		
		int ans, res;
		
		//m.print();
		
		ans = f2 * m.v[0][0] + f1*m.v[0][1] + f0*m.v[0][2] +  g2 * m.v[0][3] + g1*m.v[0][4] + g0*m.v[0][5]; 
		ans %= mod;

		res= f2*m.v[3][0] + f1*m.v[3][1] +  g2 * m.v[3][3] + g1* m.v[3][4] + f0 * m.v[3][2] + g0 *m.v[3][5];
		res %= mod;
			
		printf("%d %d\n",ans, res);
	}
	
	}
}
return 0;
}
