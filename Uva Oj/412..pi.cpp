#include<bits/stdc++.h>
using namespace std;

int gcd(int a, int b)
{
    if(b == 0)
        return a;
    else
        return gcd(b, a % b);
}

int main()
{
    //freopen("input.txt", "r", stdin);
    double pi;
    int i, n, fact, ara[55], j;

    while(scanf("%d", &n) == 1, n){
        for(i = 0; i < n; i++){
            scanf("%d",&ara[i]);
        }

        int cont = 0, total = 0;
        for(i = 0; i < n - 1;i++){
            for(j = i + 1; j < n; j++){
                fact = gcd(ara[i], ara[j]);
                total++;
                if(fact == 1)
                    cont++;
            }
        }
        if(cont == 0)
            printf("No estimate for this data set.\n");
        else
        {
            pi = (6.0/ (double)cont) *((double)total);
            pi = sqrt(pi);
            printf("%lf\n",pi);
        }
    }
    return 0;
}
