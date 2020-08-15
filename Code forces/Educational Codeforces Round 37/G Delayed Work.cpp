#include<bits/stdc++.h>
using namespace std;
int main()
{
    double k,p,x;
    while(scanf("%lf %lf %lf",&k, &p, &x)==3){
    double Min = 10000000000000;
    for(int i=1; i<=1000000; i++)
    {
        double m = i;
        double ans = k*p + (m*m*x);
        ans = ans/m;
//        printf("%lf\n",ans);
        Min = min(Min,ans);
    }
    printf("%.3lf\n",Min);
    }
}
