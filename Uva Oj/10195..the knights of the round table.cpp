#include<bits/stdc++.h>
using namespace std;
int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    double a, b, c, s, ar, rad;

    while(scanf("%lf %lf %lf",&a, &b, &c) == 3){
        if(a + b > c && b + c > a && c + a > b){
        s = (a + b + c)/ 2.0;
        ar = sqrt(s *(s - a) * (s - b) * (s - c));
        rad = ar /s;
        }
        else rad = 0.0;

        printf("The radius of the round table is: %.3lf\n",rad);
    }
    return 0;
}
