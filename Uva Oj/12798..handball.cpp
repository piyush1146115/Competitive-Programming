#include<bits/stdc++.h>
using namespace std;
int main()
{
    int cont, flag, n, cse = 0, m, i, j;
    //freopen("input.txt", "r", stdin);
    while(scanf("%d %d", &n, &m) == 2){
            cont = 0;
            cse++;
        for(i = 1; i <= n; i++){
                flag = 0;
                int g;
            for(j = 1; j <= m;j++){
                scanf("%d",&g);
                if(g <= 0)
                    flag = 1;
            }
            if(!flag)
                cont++;
        }
        printf("%d\n",cont);
    }
    return 0;
}
