#include<bits/stdc++.h>
using namespace std;
#define MX 300005
#define ff first
#define ss second
pair<long long, long long> ara[MX];
priority_queue<long long> pq;


int main()
{
    long long int n, i, j, k, l, m, ans;

    scanf("%lld", &n);

    for(i = 0; i < n; i++)
        scanf("%lld %lld",&ara[i].ff , &ara[i].ss);

    sort(ara + 1, ara + n);

    for(i = n -1; i >= 1; i--){
        if(ara[i].ff > ara[0].ff){
            pq.push(-(ara[i].ss - ara[i].ff));
        }
        else
            break;
    }

    ans =(int) pq.size() + 1;

    while(!pq.empty()){
        long long int t = -(pq.top());
        pq.pop();

        //cout << t << endl;
        if(t < ara[0].ff){
            ara[0].ff -= (t + 1);
          //  pq.pop();
            while(i >= 1){
                if(ara[i].ff > ara[0].ff){
                    pq.push(-(ara[i].ss - ara[i].ff));
                }
                else
                    break;

                i--;
            }
        }
        else
            break;

        long long int sz = (int)pq.size() + 1;

        ans = min(ans, sz);
    }

    cout << ans << endl;
}
