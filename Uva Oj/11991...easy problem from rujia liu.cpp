#include<bits/stdc++.h>
using namespace std;
struct freq{
int cont;
int ind[100];
};

struct freq f[1000005];
int main()
{
    int i, j, k, v, m, n, a, b;

    while(scanf("%d %d", &n, &m) == 2){

         for(i = 0; i <= 1000002; i++){
            f[i].cont = 0;
         }

         for(i = 0; i < n; i++ ){
            scanf("%d", &j);
            f[j].cont++;
            f[j].ind[f[j].cont] = i + 1;
         }

         for(i = 1; i <= m; i++){
            scanf("%d %d",&k, &v);
            if(f[v].cont >= k){
                printf("%d\n",f[v].ind[k]);
            }
            else{
                printf("0\n");
            }
         }
    }
    return 0;
}

