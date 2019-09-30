#include<bits/stdc++.h>
using namespace std;
int main()
{
    double a, b, x, y,v,  dis, t, mn = 1000000000.00;
    int n, i, j;

    cin >> a >> b;
    cin >> n;

    for(i = 0; i < n; i++){
        scanf("%lf %lf %lf", &x, &y, &v);

        dis = sqrt((abs(x- a)*abs(x - a)) + (abs(y - b) * abs(y - b)));
        t = dis / v;
        mn = min(t, mn);
    }
    printf("%.15lf\n",mn);
}
