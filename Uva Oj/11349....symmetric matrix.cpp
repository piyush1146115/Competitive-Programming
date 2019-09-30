#include<bits/stdc++.h>
using namespace std;
long long int mat[105][105];
int main()
{
   long long  int i, j, n, flag, test, t = 0;
    char a, b, c;
    cin >> test;

    while(test--){
        t++;
        scanf("%c %c %c %lld",&a, &b, &c, &n);

        for(i = 0; i < n; i++){
            for(j = 0; j < n; j++){
                scanf("%d",&mat[i][j]);
            }
        }
        flag = 1;
        for(i = 0; i < n; i++){
            for(j = 0; j < n; j++){

                if((mat[j][i] != mat[n - j - 1][n - i - 1]) || (mat[i][j] < 0)){
                    flag = 0;
                    break;
                }
            }
            if(flag == 0)
                break;
        }
        if(flag)
            printf("Test #%d: Symmetric.\n",t);
        else
            printf("Test #%d: Non-symmetric.\n",t);
    }
    return 0;
}
