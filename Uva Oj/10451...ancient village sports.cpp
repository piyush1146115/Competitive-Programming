#include<bits/stdc++.h>
using namespace std;
#define pi 2 *acos(0.0)

int main()
{
    double ar, cir, r, N, r2, cir2;
    int c = 0;
    while(scanf("%lf %lf",&N, &ar) == 2){
        c++;
            if(N < 3)
            break;
      r = sqrt((2*ar) / (N * sin((2 * pi)/N)));
      cir = r * r * pi;
      r2 = r*cos(pi / N);
      cir2 = r2 *r2 *pi;
      printf("Case %d: %.5lf %.5lf\n",c, cir - ar, ar - cir2);
    }
    return 0;
}
