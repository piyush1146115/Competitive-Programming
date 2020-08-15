#include<bits/stdc++.h>
using namespace std;
#define PI acos(-1)
int main()
{
    int test;
    double ans, n;

    cin >> test;

    while(test--){
        cin >> n;

        ans = (n * n) - (PI* (n/2)*(n/2));

        printf("%.2lf\n",ans);
    }
    return 0;
}
