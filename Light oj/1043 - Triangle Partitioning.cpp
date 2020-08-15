#include<bits/stdc++.h>
using namespace std;
int main()
{
    double ab, ac, bc, rat;

    int test;

    scanf("%d", &test);

    for(int tc = 1; tc <= test; tc++)
    {
        scanf("%lf %lf %lf %lf",&ab, &ac, &bc, &rat);

        double s = (ab + ac + bc)/ 2.0;
        double ar_1 = sqrt(s *(s - ab)*(s - ac)*(s - bc));
        double  ae, de;
        double lo = 0.0, hi = ab, mid;

        // printf("%lf\n",ar_1);


        while(lo < hi)
        {
            mid = (lo + hi)/2.0;

            ae = (mid / ab) * ac;
            de = (mid / ab) * bc;
            double s2 = (ae + mid +de)/2;
            double area_2 = sqrt(s2 * (s2 - mid)*(s2 - de) * (s2 - ae));

            double rato = (area_2 / (ar_1 - area_2));
//printf("%lf %lf %lf %lf\n",mid, rato, lo, hi);
            //          getchar();

            if(abs(rat - rato) <= .0000001)
                break;

            if(rato < rat)
                lo = mid;
            else
                hi = mid;
        }
        printf("Case %d: %.8lf\n",tc, mid);
    }
}
