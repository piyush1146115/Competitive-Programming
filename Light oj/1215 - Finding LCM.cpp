#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAX 1000005

vector<ll> prime, L, R, Lf, Rf;

bool chk[MAX + 5];

void sieve()
{
    for(ll i = 2; i <= MAX; i++)
    {
        if(chk[i] == 0)
        {
            for(ll j = i * i; j <= MAX; j += i)
            {
                chk[j] = 1;
            }
            prime.push_back(i);
        }
    }

//   cout << prime.size() << endl;
}

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    sieve();
    ll a, b ,l;
    int test;

    scanf("%d", &test);

    for(int tc = 1; tc <= test; tc++)
    {
        scanf("%lld %lld %lld",&a,&b,&l);

        ll gc = __gcd(a, b);
        ll lcm = (a * b)/gc;

        if(l % lcm != 0)
        {
            printf("Case %d: impossible\n",tc);
        }
        else
        {

            ll sq = sqrt(lcm) + 1;

            for(int i = 0 ; prime[i] <= sq; i++)
            {
                if(lcm % prime[i] == 0)
                {
                    ll factor = 0;

                    while(lcm % prime[i] == 0)
                    {
                        lcm /= prime[i];
                        factor++;
                    }
                    sq = sqrt(lcm) + 1;
                    L.push_back(prime[i]);
                    Lf.push_back(factor);
                }
            }
                if(lcm > 1){
                    L.push_back(lcm);
                    Lf.push_back(1);
                }

            sq = sqrt(l) + 1;

            for(int i = 0 ; prime[i] <= sq; i++)
            {
                if(l % prime[i] == 0)
                {
                    ll factor = 0;

                    while(l % prime[i] == 0)
                    {
                        l /= prime[i];
                        factor++;
                    }
                    sq = sqrt(l) + 1;
                    R.push_back(prime[i]);
                    Rf.push_back(factor);
                }
            }

            if(l > 1){
                R.push_back(l);
                Rf.push_back(1);
            }

           ll ans = 1;
            for(int i = 0, j = 0; i < R.size(); i++)
            {
                if(L[j] == R[i])
                {

                    if(Lf[j] < Rf[i])
                    {
                        while(Rf[i])
                        {
                            ans *= R[i];
                            Rf[i]--;
                        }
                    }
                    j++;
                    if(j > L.size() - 1){
                        j = 0;
                    }
                }
                else
                {
                    while(Rf[i])
                    {
                        ans *= R[i];
                        Rf[i]--;
                    }
                }
            }
            printf("Case %d: %lld\n",tc, ans);
            L.clear();
            R.clear();
            Lf.clear();
            Rf.clear();
        }
    }
}
