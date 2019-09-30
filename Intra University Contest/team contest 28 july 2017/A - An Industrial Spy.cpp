#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define Mx 100005
#define mx 10000115
#define inf 1<<28
ll status[mx+5];
vector<int>prime;
void sieve(){
   long long int  i,j;
    for(i=2;i<=mx;i++)
    {
        status[i]=0;
    }
    for( i=2;i<=sqrt(mx);i++){
        if(status[i]==0)
        {
            for(j=i*i;j<=mx;j+=i){
                status[j]=1;
            }
        }
    }
    for(i=2;i<=mx;i++){
        if(status[i]==0)
            prime.push_back(i);
    }
}
#define dd double
#define sc scanf
#define pr printf
#define VI vector<int>
#define VS vector<string>
#define VC vector<char>
#define VLL vector<long long int>
#define FILE freopen("input.txt","rt",stdin); freopen("output.txt","w",stdout);
#define p_b push_back
#define mem(x,y) memset(x,y,sizeof(x))
#define F(i,a,b) for(i=a;i<=b;i++)
#define sc1(a) scanf("%d",&a)
#define sc2(a,b) scanf("%d%d",&a,&b)
#define sc3(a,b,c) scanf("%d%d%d",&a,&b,&c)
int main()
{
    sieve();
    string A;
    int test;
    sc1(test);
    while(test--){
    //map<char,int>mp;
    int mp1[10],mp2[10];
    cin>>A;
    int sz=A.size();
    int k=0;
    mem(mp1,0);
    for(int i=0;i<A.size();i++){
        int v=A[i]-'0';
        mp1[v]++;

      //  if(i!=A.size()-1)
            //k++;
    }
    int Z;
    if(sz==1)Z=9;
    if(sz==2)Z=99;
    if(sz==3)Z=999;
    if(sz==4)Z=9999;
    if(sz==5)Z=99999;
    if(sz==6)Z=999999;
    if(sz==7)Z=9999999;
    int sum=0;
    mem(mp2,0);
    //if(mp1[2]>0)sum++;
    for(int i=0;;i++){
            int f=0;
            if(prime[i]>Z)break;
            //cout<<prime[i]<<" ";
            int m=prime[i];
        while(m>0){
            int rem=m%10;
            m=m/10;
            mp2[rem]++;
            if(mp2[rem]>mp1[rem])f=1;
        }
        mem(mp2,0);
        if(f==0 && status[prime[i]]==0)sum++;
    }
    pr("%d\n",sum);
}

}
