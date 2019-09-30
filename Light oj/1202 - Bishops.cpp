#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long test, r1, c1, r2, c2;

    cin >> test;

    for(int tc = 1; tc <= test; tc++) {

        cin >> r1 >> c1 >> r2 >> c2;
        long long dr, dc;

        dr = abs(r1 - r2);
        dc = abs(c1 - c2);

        printf("Case %d: ",tc);

        if(dr == dc)
            printf("1\n");
        else {
            long long dif = abs(dr - dc);

                 if(dif % 2 == 0)
                        printf("2\n");
            else
                printf("impossible\n");
        }
    }
    return 0;
}
