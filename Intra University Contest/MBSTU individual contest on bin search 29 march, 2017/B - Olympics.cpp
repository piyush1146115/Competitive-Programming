#include<bits/stdc++.h>
using namespace std;

double a, b;

double calc(double ab)
{
    double bc = ab * (a / b);
    double ac = sqrt(ab*ab + bc*bc);
    double r = ac / 2.0;
    double theta = acos((2.0*r*r - (ab*ab))/(2.0*r*r));
    double s = r * theta;
    double perim = 2.0*s + 2.0*bc;

    return perim;
}

int main()
{
    int test;

    scanf("%d",&test);

    for(int tc = 1; tc <= test; tc++){
        scanf("%lf : %lf",&a, &b);


        double lo = 0.0, hi = 400.0, mid;

        while(1){

            mid = (lo + hi)/2.0;
          //  printf("%lf %lf\n",mid, calc(mid));
           // getchar();

            if(calc(mid) > 400.0){
                hi = mid;
            }
            else
            {
                lo = mid;
            }
            if(abs(calc(mid) - 400) <= 1e-7){
                break;
            }
        }
        double width = mid, length = (a / b)* mid;

        printf("Case %d: %.10lf %.10lf\n",tc,length, width);
    }
}
