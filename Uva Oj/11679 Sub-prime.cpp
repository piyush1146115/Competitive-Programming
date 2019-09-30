#include<bits/stdc++.h>
using namespace std;
long long ara[50];
int main()
{
    int n, b, d, c, v, i, j;

    while(scanf("%d %d",&b, &n) == 2){
        if(b == 0 && n == 0)
            break;
        for(i = 1; i <= n; i++)
            scanf("%lld",&ara[i]);

        //memset(ara, 0, sizeof(ara));

        int flag = 1;
        while(n--){
            scanf("%d %d %d", &d, &c,&v);
            ara[d] -= v;
            ara[c] += v;

        }

        for(i = 1; i <= b; i++){
                //cout << ara[i] << endl;
            if(ara[i] < 0)
            flag = 0;
        }

        if(flag == 0)
            printf("N\n");
        else
            printf("S\n");
    }
}
