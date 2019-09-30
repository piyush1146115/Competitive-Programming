#include<bits/stdc++.h>
using namespace std;
double ara[5005], cum[5005];

int main()
{
    int n, k;

    scanf("%d %d", &n, &k);

    for(int i = 1; i <= n; i++){
        scanf("%lf", &ara[i]);
    }

    cum[0] = 0.0;

    for(int i = 1; i <= n; i++){
        cum[i] = ara[i] + cum[i - 1];
    }

    double ans = 0.0;
    for(int i = 1; i <= n; i++){
        for(int j = i + k -1; j <= n; j++){
            double dif = (double)(j - i + 1);
            double avg = (double)(cum[j] - cum[i - 1])/dif;
            ans = max(ans, avg);
        }
    }

    printf("%.10lf\n",ans);
}
