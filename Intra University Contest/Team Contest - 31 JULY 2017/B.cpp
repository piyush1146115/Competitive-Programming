#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t,w = 0;
    cin>>t;
    while(t--)
    {
        double x1,y1,x2,y2,x3,y3,x4,y4 ,cost;
        scanf("%lf %lf %lf %lf %lf %lf %lf %lf",&x1, &y1,&x2, &y2, &x3, &y3, &x4, &y4);
        scanf("%lf",&cost);

        double area = (x1 * y2) - (x2*y1) + (x2 * y3) - (y2 * x3) + (x3 * y4) - (y3 * x4) + (x4 * y1) - (y4  * x1);
        if(area<0.0) area *= -1.0;
        area/=2.00;
        printf("Case #%d: %.2lf\n",++w,cost/area);
    }
}
