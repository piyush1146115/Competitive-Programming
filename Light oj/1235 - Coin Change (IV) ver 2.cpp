#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll ara[40];
ll n, k;
vector<ll> a, b;
 
void makea(ll m)
{
	a.push_back(0);
	a.push_back(ara[0]);
	a.push_back(ara[1]);
	a.push_back(ara[1] + ara[0]);
	
    
    for(int i = 2; i < m; i++){
		for(int j = 0; j < (1 << i); j++){
			a.push_back(a[j] + ara[i]);
		}
	}
}
 
void makeb(ll m)
{
	b.push_back(0);
	b.push_back(ara[n/2]);
	b.push_back(ara[n/2 + 1]);
	b.push_back(ara[n/2 + 1] + ara[n/2]);
	
    
    for(int i = 2; i < m; i++){
		for(int j = 0; j < (1 << i); j++){
			b.push_back(b[j] + ara[i + n/2]);
		}
	}
}
 
int bin()
{
    sort(b.begin(), b.end());
   
    ll v = a.size();
    for(int i = 0; i < v; i++){
        ll need = k - a[i];
        ll hi = b.size() - 1;
        ll lo = 0;
       
        while(lo <= hi){
            ll mid = (lo + hi)/2;
           
            if(need == b[mid]){
                return 1;
            }
            if(b[mid] < need){
                lo = mid + 1;
            }
            else{
                hi = mid -1;
            }
        }
    }
    return 0;
}
 
int main()
{
    int test;
    scanf("%d",&test);
   
    for(int tc = 1; tc <= test; tc++){
        scanf("%lld %lld",&n, &k);
       
        n *= 2;
       
        for(int i = 0; i < n; i += 2){
        scanf("%lld",&ara[i]);
        ara[i + 1] = ara[i];
    }
       
        makea(n/2);
        makeb(n - n/2);
       
        int ans = bin();
       
        if(ans)
        printf("Case %d: Yes\n",tc);
        else
        printf("Case %d: No\n",tc);
        a.clear();
        b.clear();
    }
    return 0;
}
 
