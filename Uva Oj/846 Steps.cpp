#include<bits/stdc++.h>
using namespace std;
int main()
{
  //  freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    long long x, y, dif, n, i, j, k,ans;
    int test;

    scanf("%d", &test);

    while(test--){
        scanf("%lld %lld", &x, &y);

        dif = abs(x - y);
        n = 1;
        ans = 0;
        while(dif > 0){
            dif -= n;

                //cout << dif << " " << n << endl;
               if(dif  < (n * (n  + 1) / 2)){
                if(n > 1)
                    n--;
               }

           else if((dif - (n + 1)) >= (n * (n + 1)) / 2)
           n++;
            ans++;
        }
        cout << ans << endl;
    }
    return 0;
}
