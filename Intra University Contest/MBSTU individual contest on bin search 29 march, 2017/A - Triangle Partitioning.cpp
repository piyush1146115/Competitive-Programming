#include<bits/stdc++.h>
using namespace std;

double area(double a, double b, double c)
{
    double s = (a + b + c)/2.0;

    double ans = sqrt(s * (s - a) * (s - b)*(s - c));

    return ans;
}


int main()
{
    int test;

    scanf("%d", &test);

    for(int tc = 1; tc <= test; tc++){
        double ab, ac, bc, rat;

        scanf("%lf %lf %lf %lf",&ab, &ac, &bc, &rat);

        double lo = 0.0, hi = ab, mid;

        while(abs(lo - hi) >= .000000001){
            mid = (lo + hi)/2.0;
            double ae, de;

            ae = (mid / ab) * ac;
            de = (mid / ab) * bc;

            double tri_1, tri_2, trap;

            tri_1 = area(mid, ae, de);
            tri_2 = area(ab, ac, bc);

            trap = tri_2 - tri_1;

            double r = tri_1 / trap;

            if(abs(r - rat) < .000000001)
                break;

            if(r > rat)
                hi = mid;
            if(r < rat)
                lo = mid;
        }

        printf("Case %d: %.10lf\n",tc,mid);
    }
}
