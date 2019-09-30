#include<bits/stdc++.h>
using namespace std;

int main()
{
//    freopen("input.txt", "r", stdin);
  //  freopen("output.txt", "w", stdout);

        unsigned long long hi, lo, s1, s2, ans, i, j;

    while(scanf("%llu %llu", &lo, &hi) == 2){

        if(lo == 0 && hi == 0)
            break;

        s1 = lo / 5;
        s2 = hi / 5;

        ans = s2 - s1 + 1;

        printf("%llu\n", ans);
    }
    return 0;
}
