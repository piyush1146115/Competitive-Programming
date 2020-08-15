#include<bits/stdc++.h>
using namespace std;

int main()
{
    double an[5], r[5], a, b, c, arc[5], res, tr, s;
    int i, j, test;

    cin >> test;

    while(test--){
    scanf("%lf %lf %lf", &r[1], &r[2], &r[3]);

    a = r[2] + r[3];
    b = r[1] + r[3];
    c = r[1] + r[2];

    s = (a + b + c)/2.0;
    tr = sqrt(s * (s - a) * (s - b) * (s - c));

    an[1] = acos(((b*b + c*c) - a*a)/(2*b*c));
    an[2] = acos(((a*a + c*c) - b*b)/ (2*a*c));
    an[3] = acos(((a*a + b*b) - c*c)/ (2*a*b));



    arc[1] = 0.5 * an[1] * r[1] * r[1];
    arc[2] = 0.5 * an[2] * r[2] * r[2];
    arc[3] = 0.5 * an[3] * r[3] * r[3];
    //printf("%lf %lf\n",s, tr);
    res = tr - arc[1] - arc[2] - arc[3];

    printf("%.6lf\n",res);
    }
    return 0;
}
