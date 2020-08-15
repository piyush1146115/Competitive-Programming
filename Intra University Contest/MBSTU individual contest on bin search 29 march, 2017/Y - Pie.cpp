#include<bits/stdc++.h>
using namespace std;
#define mxx  10005
#define eps 1e-5
#define pi acos(-1.0)

double ara[mxx];
int n, f;

bool chk(double v)
{
    int cnt = 0;
    for(int i = 0; i < n; i++){
        double  d = (ara[i] / v);
        cnt += (int)d;
    }
    if(cnt >= f)
        return true;
    else
        return false;
}

int main()
{
    int test;
    scanf("%d", &test);

    for(int tc = 1; tc <= test; tc++)
    {
        double lo = 0.0, hi = 0.0, mid, r;
        scanf("%d %d", &n, &f);
        f++;
        for(int i = 0; i < n; i++)
        {
            scanf("%lf", &r);
            ara[i] = pi * r * r;
           // printf("%.6lf\n",ara[i]);

            hi += ara[i];
        }

        double ans;
        while(abs(hi - lo) >= eps){
            mid = (lo + hi)/2.0;
            if(chk(mid)){
                lo = mid;
                ans = mid;
            }
            else{
                hi = mid;
            }
        }
        printf("%.4lf\n", ans);
    }
    return 0;
}
