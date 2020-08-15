#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n, i, j, test;
    double c[3005], a0, an;

    scanf("%d", &test);

    while(test--){
        scanf("%d", &n);
        scanf("%lf %lf", &a0, &an);

       double sum = 0;
        for(i = 0; i < n ;i++){
            scanf("%lf", &c[i]);
            sum += (2 * (n -i) * c[i]);
        }
       double res;
       res = (n * a0 + an - sum)/ (n + 1);
        res += 1e-9;
        printf("%.2lf\n", res);

        if(test)
            printf("\n");
    }
    return 0;
}
