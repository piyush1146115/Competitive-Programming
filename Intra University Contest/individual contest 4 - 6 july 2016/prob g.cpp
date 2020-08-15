#include<bits/stdc++.h>
using namespace std;
#define s(n) n*n
#define pi 2 * acos (0.0)
int main()
{
    double r, a_sq, res, a_cr;
    int test, c = 0;

    cin >> test;

    while(test--){
        cin >> r;
        c++;
        a_sq = s(2 * r);
        a_cr = pi * s(r);
        res = a_sq - a_cr;
        printf("Case %d: %.2lf\n",c, res);
    }
    return 0;
}
