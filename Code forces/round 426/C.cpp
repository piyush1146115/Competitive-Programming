#include<bits/stdc++.h>
using namespace std;
#define ll long long 

vector<ll> prime;
int chk[100005];

void sieve()
{
	for(int i = 3; i * i <= 100000; i += 2){
		for(int j = i* i; j <= 100000; j+= (i* 2)){
			chk[j] = 1;
		}
	}
	
	prime.push_back(2);
	
	for(int i = 3; i <= 100000; i+= 2){
		if(chk[i] == 0)
		prime.push_back(i);
	}
}

int main()
{
	sieve();
	ll test;
	//cin >> n;
	scanf("%lld",&test);
	
	for(int tc = 1; tc <= test; tc++){
		ll a, b;
		vector<ll> va, vb;
		map<ll, ll> mpa, mpb;
		scanf("%lld %lld",&a,&b);
		
		for(int i = 0; prime[i] * prime[i] <= a; i++){
			if(a % prime[i] == 0){
				va.push_back(prime[i]);
				while(a % prime[i] == 0){
					mpa[prime[i]]++;
					a /= prime[i];
				}
			}
		}
		if(a > 1){
			mpa[a]++;
			va.push_back(a);
		}
			
		for(int i = 0; prime[i] * prime[i] <= b; i++){
			if(b % prime[i] == 0){
				vb.push_back(prime[i]);
				while(b % prime[i] == 0){
					mpb[prime[i]]++;
					b /= prime[i];
				}
			}
		}
		
		if(b > 1){
			mpb[b]++;
			vb.push_back(b);
		}
		/*
		cout << "printing va\n";
		for(int i = 0; i < (int)va.size(); i++)
		cout << va[i] << " " << mpa[va[i]] << endl;
		cout << " printing vb\n";
		for(int i = 0; i < (int)vb.size(); i++)
		cout << vb[i] << " " << mpb[vb[i]] << endl;
		*/
		int flag = 1;
		
		for(int i = 0; i < (int)va.size(); i++){
			if(mpa[va[i]] > 0 && mpb[va[i]] == 0)
			{
				flag = 0;
				break;
			}
			if(mpa[va[i]] % 2 == 0){
				if(mpb[va[i]] % 2 == 0){
					flag = 0;
					break;
				}
			}
			else{
				if(mpa[va[i]] == mpb[va[i]] && mpa[va[i]] == 3){
					continue;
				}
				
				if(mpb[va[i]] % 2 == 1){
					flag = 0;
					break;
				}
			}
		}
		
		if(flag)
		printf("Yes\n");
		else
		printf("No\n");
	}
	
}
