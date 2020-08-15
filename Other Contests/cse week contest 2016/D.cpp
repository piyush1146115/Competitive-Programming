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
    while(p >= 1)
    {
        if(p % 2 == 1)
        {
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
    if(p % 2 == 0)
    {
        T ans = bigmod(b, p/2, mod);
        return ((ans % mod) * (ans % mod)) % mod;
    }
    else
        return ((b % mod) * (bigmod(b, p - 1, mod) % mod)) % mod;
}

int fact(int n)
{
    int sum = 1;
    for(int i = 1; i <= n; i++)
        sum *= i;

    return sum;

}
int ara[] = {2, 3,5, 7, 11, 13};

int main()
{
    int n , m, i, j,k;
    map<int, int> m1, m2;

    while(sf("%d %d",&m, &n) == 2)
    {
        if( m == 0 && n == 0)
            break;

        for(i = 0; i < m ; i++)
        {
            sf("%d",&k);
            if(k == 0)
                continue;
            for(j = 2; j <= k ; j++)
            {
               int  temp = j;
                for(int x = 0 ; x < 5; x++)
                {
                    while(temp % ara[x] == 0)
                    {
                        m1[ara[x]]++;
                        temp /= ara[x];
                        //cout << temp << " " << ara[x]<< endl;
                    }
                }
                if(temp > 1)
                {
                    m1[temp]++;
                    }
        }
        }

        for(i = 0; i < n ; i++)
        {
            sf("%d",&k);
            if(k == 0)
                continue;
            for(j = 1; j <= k ; j++)
            {
               int  temp = j;
                for(int x = 0 ; x < 5; x++)
                {
                    while(temp % ara[x] == 0)
                    {
                        m2[ara[x]]++;
                        temp/= ara[x];
                    }
                }
                if(temp > 1)
                {
                    m2[temp]++;
                }
            }
        }

            bool flag = 1;

            for( i = 1; i < 10; i++)
                if(m1[i] != m2[i])
                    flag = 0;

            if(flag)
                pf("YES\n");
            else
                pf("NO\n");

            m1.clear();
            m2.clear();
        }
        return 0;
    }
