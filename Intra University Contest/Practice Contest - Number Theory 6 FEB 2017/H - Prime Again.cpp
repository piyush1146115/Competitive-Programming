#include<bits/stdc++.h>
using namespace std;
#define ll long long

vector<int> prime;
bool chk[66010];

void sieve()
{
	prime.push_back(2);
	
	for(int i = 3; i <= 260; i+= 2)
	{
		if(chk[i] == 0){
			for(int j = i * i;j <= 66000; j += (i * 2)){
				chk[j] = 1;
			}
		}
	}
	
	for(int i = 3; i <= 66000; i += 2)
	if(chk[i] == 0)
	prime.push_back(i);
	
}

bool isprime(ll n)
{
	ll sq = sqrt(n) + 1;
	if(n == 1)
	return false;
	
	for(int i = 0; prime[i] <= sq; i++){
	if(n % prime[i] == 0)
	{
		return false;
	}
	}
	return true;
}

int main()
{
	sieve();
	
	ll test;
	
	scanf("%lld",&test);
	
	for(ll tc = 1; tc <= test; tc++){
		
		ll n;
		scanf("%lld", &n);
		
		if(n == 3){
		printf("2\n");
		continue;
	}
		if(n  % 2 == 0){
		for(ll i = n - 1; i >= 3; i -= 2){
		if(isprime(i)){
		printf("%lld\n", i);
		break;
	}
}
	}
	else{
	for(ll i = n - 2; i >= 3; i -= 2){
		if(isprime(i)){
		printf("%lld\n", i);
		break;
	}

}
	}
}
return 0;
}

