#include<bits/stdc++.h>
using namespace std;
#define ll long long
vector<int>prime;
bool chk[355];
vector<ll>ans[10005];

void sieve()
{
    for(int i = 3; i <= 25; i+= 2){
        if(chk[i] == 0){
            for(int j = i * i; j <= 350; j += (i * 2)){
                chk[j] = 1;
            }
        }
    }
    prime.push_back(2);

    for(int i = 3; i <= 350; i += 2)
    if(chk[i] == 0){
        prime.push_back(i);
    }

}

ll NOD(ll v)
{
    ll sum = 1;
    for(int i = 0; prime[i]*prime[i] <= v  && i <prime.size(); i++){

        if(v % prime[i] == 0){
            int cnt = 0;
            while(v % prime[i] == 0){
                v /= prime[i];
                cnt += 2;
            }
            sum *= (cnt + 1);
        }
    }
    if(v > 1)
        sum *= 3;
    return sum;
}

void solve()
{
    for(ll i = 1; i <= 100001; i++){
        ll res = NOD(i);
        ll v = (ll)(i  * i);
        ans[res].push_back(v);
    }
}

int main()
{
   sieve();
   solve();
   int test;
   scanf("%d", &test);

   while(test--){
    ll left, right, k;
    scanf("%lld %lld %lld", &k, &left, &right);
   vector<ll> :: iterator beg, en;

    beg = lower_bound(ans[k].begin(), ans[k].end(), left);
    en = upper_bound(ans[k].begin(), ans[k].end(), right);
    ll fin = en - beg;
    printf("%lld\n",fin);
   }
   return 0;

}
