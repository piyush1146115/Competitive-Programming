#include<bits/stdc++.h>
using namespace std;
int main()
{
    double v, l, f, s, n;

    while(scanf("%lf %lf",&l, &f) == 2 && (l != 0 || f != 0)){

        v = sqrt(l * 2 * f);
        s = (v * 3600) / ( 2 * l);

        printf("%.8lf %.8lf\n",v, s);
    }

    return 0;
}
