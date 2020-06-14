#include <bits/stdc++.h>
#define mxx 4000009
using namespace std;
bool isprime[mxx+15];
long long phi[mxx+15];
long long result[mxx+15];
void totient()
{
    phi[1]=1;
    for(long i=2; i<mxx; i+=2)
    {
        phi[i]=i/2;
    }
    for(long i=3; i<mxx; i+=2)
    {
        phi[i]=i;;
    }
    for(long i=3; i<mxx; i+=2)
    {
        if(isprime[i]==false)
        {
            phi[i]=i-1;
            for(long j=i+i; j<mxx; j+=i)
            {
                phi[j]-=(phi[j]/i);
                isprime[j]=true;
            }
        }
    }
}
void extremeGcd()
{
    for(long d=1; d<mxx/2; d++)
    {
        for(long i=2; (i*d)<mxx; i++)
        {
            result[i*d]+=(d*phi[i]);
        }
    }
        for(long i=2; i<mxx; i++)
        {
            result[i]+=result[i-1];
        }
}
int main()
{
    totient();
    extremeGcd();
    long n;
    while(scanf("%ld",&n)==1 and n)
    {
        cout<<result[n]<<endl;
    }
}
