#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ll t,w = 0;
     cin>>t;
    while(t--)
    {
        ll x1,y1,x2,y2,x3,y3,x4,y4 ,cost;
        scanf("%lld %lld %lld %lld %lld %lld %lld %lld",&x1, &y1,&x2, &y2, &x3, &y3, &x4, &y4);
        scanf("%lld",&cost);
//        cin>>x1>>y1>>x2>>y2>>x3>>y3>>x4>>y4>>cost;

        ll area = -(x2*y1) - (y4  * x1) - (y2 * x3) + (x3 * y4) - (y3 * x4) + (x4 * y1) + (x1 * y2) + (x2 * y3);
//        area/=2.00;
        if(area<0) area *= -1;

        double ans;

        if(area == 0 || cost<=0.000 ) ans = 0.0;
        else ans = ((double)area *.50) /  ((double)cost);
//         Min = min(ans, Min);
        printf("Case #%lld: %.2lf\n",++w,ans);
    }
