#include<bits/stdc++.h>
using namespace std;
#define MAX 10005
#define ll long long

ll cnt[MAX], res[MAX];

int main()
{
    int test;
    scanf("%d", &test);

    for(int tc = 1; tc <= test; tc++){
        int n;
        scanf("%d", &n);
        memset(cnt, 0, sizeof(cnt));
       // memset(res, 0, sizeof(res));


        for(int i = 1; i <= n; i++){
            int k;
            scanf("%d",&k );
            cnt[k]++;
        }

        for(int i = 10000; i >= 1; i--){
          ll sum = 0, r = 0;
          res[i] = 0;
          for(int j = i; j <= 10000; j+= i){
            sum += cnt[j];
            r += res[j];
          }
          if(sum > 3){
               // cout << "test >> " << i << " sum " << sum <<  " r " << r << endl;
            res[i] = (sum * (sum -1)* (sum - 2) * (sum -3))/24;
            res[i] -= r;
            res[i] = max(0ll, res[i]);
          }
        }

        printf("Case %d: %lld\n",tc, res[1]);
    }
}
