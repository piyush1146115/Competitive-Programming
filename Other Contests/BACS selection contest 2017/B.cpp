#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mxx 5005
ll ara[mxx], neg[mxx];

int main()
{
    int test;
    scanf("%d", &test);

    for(int tc = 1; tc <= test; tc++){
        int n, k;

        scanf("%d %d",&n, &k);

        memset(neg, 0, sizeof(neg));

        for(int i = 0; i < n; i++){
            scanf("%lld", &ara[i]);
        }

        ll p1 = 0;
        ll sum = 0, cnt = 0, ans = 0, mx = -INT_MAX;
    for(int j = 0; j < n; j++){
            sum = 0;
            cnt = 0;
        priority_queue<long long int> pq;
            mx = max(mx, ara[j]);
            if(ara[j] < 0)
                continue;

        for(int i = j; i < n; i++){

            if(ara[i] < 0){
                cnt++;
                pq.push(ara[i]);

                if(cnt > k){
                    sum += pq.top();
                   // cout << pq.top() << endl;
                    pq.pop();
                    cnt--;
                }
            }
            else
                sum += ara[i];

                    if(sum <= 0){
                        sum =  0;
                        while(!pq.empty()){
                            pq.pop();
                        }
                        cnt = 0;
                    }

            ans= max(ans, sum);
        }
    }

        printf("Case %d: ",tc);

        if(k == 0 && ans == 0){
            printf("%lld\n",mx);
        }
        else{
            printf("%lld\n",ans);
        }

    }
    return 0;
}

/**
2
5 3
1 2 3 4 5
7 2
1 -4 1 -10 -11 2 -6
*/
