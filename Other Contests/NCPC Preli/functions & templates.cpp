#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ff first
#define ss second
#define pii pair<int, int>
#define mp make_pair
#define pb push_back


template<typename T>inline T  SQ(T a)
{
    return a*a;
}
template<typename T>inline T GCD(T a, T b)
{
    if (b == 0)return a;
    else return GCD(b, a % b);
}
template<typename T>inline T LCM(T a, T b)
{
    ll res=a*b;
    res/=GCD(a,b);
    return res;
}

template<typename T>inline T BIGMOD(T a, T b, T m)
{
    if (b == 0)return 1;
    else if (b % 2 == 0)return SQ(BIGMOD(a, b / 2, m)) % m;
    else return (a % m*BIGMOD(a, b - 1, m)) % m;
}

template<typename T> inline T power(T b, T p)
{
	if(p == 0)return 1;
	else if(p %2 == 0) return SQ(power(b, p/2));
	else return (b * power(b, p - 1));
}

template<typename T>inline ULL  DIST(T A,T B)
{
    ULL res=(A.x-B.x)*(A.x-B.x)+(A.y-B.y)*(A.y-B.y);
    return res;
}


/*
 * bool chk[mxx];
 * sieve()
 * {
 * for(int i = 4; i <= mxx; i += 2)
 * chk[i] = 1;
 * 
 * 
 * for(int i = 3; i* i <= mxx; i += 2){
 * 		if(chk[i] == 0)
 * 		{
 * 		for(j = i * i; j <= mxx; j += (i << 2))
 * 		chk[j] = 1;
 * }
 * }
 * 
 *
 * }
 * 
 */
 
