#include<bits/stdc++.h>
using namespace std;
int main()
{
   long long  int i , j , k, n, m, sq, ans;

    while(scanf("%lld", &n) == 1){
        if(n < 0){
            break;
        }
        bool check = 1;
        //ans = 15465105454;
        sq = sqrt(n);

        for(i = sq + 1; i > 1; i--){
            k = i;
            m = n;
            while(k--){
                m--;
                j = m / i;
                if(m % i != 0)
                    break;

                m -= j;
            }
                //cout << m << " " << i << " " << k << endl;

            if((m % i == 0 ) && k == -1){
               // ans = min(ans, i);
                //cout << i << endl;
                printf("%lld coconuts, %lld people and 1 monkey\n",n, i);
                check = 0;
                break;
            }
        }
        if(check){
            printf("%lld coconuts, no solution\n", n);
        }
    }
    return 0;
}
