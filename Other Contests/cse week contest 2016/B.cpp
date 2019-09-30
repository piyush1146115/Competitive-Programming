#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define pf printf
#define sf scanf

#define mxx 1000005
template<typename T> inline T sq(T a)
{
    return a*a;
}

template<typename T> inline T gcd(T a, T b)
{
    if(b == 0)
        return a;
    else return gcd(b, a % b);
}



template<typename T> inline T power(T b, T p)
{
    T ans = 1;
    while(p >= 1){
        if(p % 2 == 1){
            ans *= b;
        }
        p /= 2;
        b *= b;
    }
    return ans;
}

template <typename T> inline T bigmod(T b, T p, T mod)
{
    if(p == 0)
        return 1;
    if(p % 2 == 0){
        T ans = bigmod(b, p/2, mod);
        return ((ans % mod) * (ans % mod)) % mod;
    }
    else
        return ((b % mod) * (bigmod(b, p - 1, mod) % mod)) % mod;
}

int ara[mxx + 5];

int main()
{
    int n,i , j, cs = 0;

    while(sf("%d", &n) == 1){
        if(n == 0)
            break;
        for(i = 0; i < n; i++)
            sf("%d",&ara[i]);

        int co = 0;

        for(i = 1 ; i  < n -1; i++)
        {
            if(ara[i] > 0 && ara[i] > ara[i - 1] && ara[i] > ara[i + 1]){
              co++;
            }
        }
        printf("Case %d: %d\n",++cs, co);
    }
    return 0;
}

