#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define pf printf
#define sf scanf

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

int main()
{
    int n, i , j,ty, fr;
    string s;
    vector<string> vs;

    while(sf("%d",&n) == 1){
        while(n--){
            cin >> s >> ty >> fr;
            if(ty == 1 || fr >= 30){
                vs.push_back(s);
            }

            for(i = 0; i < vs.size(); i++)
                cout << vs[i] << endl;

            vs.clear();
        }
    }
}

