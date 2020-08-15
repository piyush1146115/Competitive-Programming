#include<bits/stdc++.h>
using namespace std;
int main()
{
    double x, y, dif, ans;

    while(scanf("%lf %lf",&x, &y) == 2){
        dif = y - x;
        ans = ceil(y / dif);

        printf("%.0lf\n",ans);
    }
    return 0;
}
