#include<bits/stdc++.h>
using namespace std;
struct car{
char name[30];
long long int down, up;
}c[10005];
int main()
{
    freopen("input.txt", "r", stdin);
    long long test, j, k, n, m, data;
    int i;
    scanf("%lld", &test);

    while(test--){

        scanf("%lld",&data);
        for(i = 0; i < data; i++){
            scanf("%s", c[i].name);
            scanf("%lld %lld",&c[i].down ,&c[i].up);
        }
       /* for(i = 0; i < data; i++)
            printf("%s\n",c[i].name);*/
        int q;
        cin >> q;

        while(q--){
            scanf("%lld",&n);
            int cont = 0, ind;
            for(i = 0; i < data; i++){
                if(n >= c[i].down && n <= c[i].up){
                    cont++;
                    ind = i;
                }
        }
        if(cont == 1){
            printf("%s\n",c[ind].name);
        }
        else
        printf("UNDETERMINED\n");
    }
    if(test)
        printf("\n");
    }
    return 0;
}
