#include<bits/stdc++.h>
using namespace std;

int main()
{
    double ara[12], avg, m;
    long long int i, j, k, test, n,  caseno = 0, value[10];
    //freopen("input.txt", "rt", stdin);
    scanf("%lld", &test);

    while(test--){
         avg = 0;
        for(i = 0; i < 12; i++){
            scanf("%lf", &ara[i]);
            avg += ara[i];
        }

        avg /= 12.00;
          n = avg/ 1000;
        m = avg  - (n * 1000);

        if(n >= 1)
        printf("%lld $%lld,%.2lf\n",++caseno, n, m);
        else
            printf("%lld $%.2lf\n",++caseno, avg);
    }
    return 0;
}
