#include<bits/stdc++.h>
using namespace std;
struct point{
double x, y;
};
int main()
{
    point a, b, o;
    double oa, ob, ab, ang, ans;
    int test, i;
    scanf("%d", &test);

    for(i = 1; i <= test; i++){
        scanf("%lf %lf %lf %lf %lf %lf",&o.x, &o.y, &a.x, &a.y, &b.x, &b.y);

        oa = sqrt(((a.x - o.x) * (a.x - o.x)) + ((a.y - o.y) * (a.y - o.y)));
        ob = sqrt(((b.x - o.x) * (b.x - o.x)) + ((b.y - o.y) * (b.y - o.y)));
        ab = sqrt(((a.x - b.x) * (a.x - b.x)) + ((a.y - b.y) * (a.y - b.y)));

        ang = acos(((oa * oa) + (ob * ob) - (ab * ab))/ (2 *oa * ob));
        ans = oa * ang;

        printf("Case %d: %.12lf\n", i, ans);
    }
    return 0;
}
