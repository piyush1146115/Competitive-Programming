#include<bits/stdc++.h>
using namespace std;
#define ll long long 
#define mxx 110005

vector<ll> prime;
ll  ara[mxx], flag[100010];

void sieve()
{
	prime.push_back(2);
	int sq = 100005;
	
	//cout << sq << endl;
	for(int i = 3; i * i <= sq; i += 2){
		if(flag[i] == 0){
			for(int j = i * i; j <= sq; j+= (i*2)){
				flag[j] = 1;
			}
		}
	}
	
	for(int i = 3; i <= sq; i += 2 )
	if(flag[i] == 0){
		//cout << i << endl;
		prime.push_back(i);
	}
	
	//cout << prime[1] << endl;
}


int segmentsieve(ll a, ll b)
{
	if(a == 1)
	a++;
	
	//int sq = sqrt(b);
	
	int sum = 0;
	memset(ara, 0, sizeof(ara));
	
	for(ll i = 0; i < (int)prime.size() && (prime[i] * prime[i]) <= b ; i++){
		ll p = prime[i];
		//cout << prime[i] << endl;
		ll j = p * p;
		
		if(j < a)
		j = ((a + p - 1)/p) * p;
		//cout << " j " << j << endl;	
		for( ; j <= b; j += p)
		ara[j - a] = 1;
	}
	
	for(ll i = a; i <= b; i++){
		if(ara[i - a] == 0)
		sum++;
	}
	
	return sum;
}

int main()
{
	sieve();
	int test;
	scanf("%d", &test);
	
	for(int tc = 1; tc <= test; tc++){
	ll a, b;
	scanf("%lld %lld",&a, &b);
	if(a > b)
	swap(a,b);
	
	int ans = segmentsieve(a, b);
	printf("Case %d: %d\n",tc, ans);
}

}
