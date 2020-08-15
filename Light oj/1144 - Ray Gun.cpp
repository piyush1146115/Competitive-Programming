#include<bits/stdc++.h>
using namespace std;
#define MAX 1000006
#define ll long long
ll flag[MAX];
bool prime[MAX];
void mobious(int n){

    for(ll i = 1; i <= n; i++){
        flag[i] = 1ll;
    }

    for(ll i = 2; i <= n; i++){
        if(prime[i] == 0){
             // cout << "test " << i << endl;
                flag[i] *= -1;
            for(ll j = i * 2; j <= n; j += i){
                flag[j] *= -1;
                prime[j] = 1;
            }
            ll sq = i* i;
            for(ll j = sq; j <= n; j+= sq){
                flag[j] = 0;
            }

        }
    }

}

int main()
{
    mobious(1000002);

    int test;

    scanf("%d", &test);

    for(int tc = 1; tc <= test; tc++)
    {
        ll m, n;
        scanf("%lld %lld", &m, &n);

        ll mn = min(m,n);

        ll mul = m*n;
        if(mul >= 1)
            mul += 2ll;

        if((m > 0 || n > 0) && (mul == 0))
            mul = 1;

        for(ll i = 2; i <= mn; i++){
            mul += (flag[i] * (m/i) * (n/i));
        }

        printf("Case %d: %lld\n",tc, mul);
    }
}
