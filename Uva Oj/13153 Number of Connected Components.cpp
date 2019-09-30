#include<bits/stdc++.h>
using namespace std;
#define mxx 1000005
vector<int> prime;
vector<int> pf[mxx];
bool  chk[1050];
int ara[100005],flag[mxx], par[mxx], rn[mxx];

void sieve()
{
	for(int i = 3; i < 50; i += 2){
		if(chk[i] == 0)
		for(int j = i * i; j <= 1010; j += (i * 2))
		{
			chk[j] = 1;
		}
	}
	
	prime.push_back(2);
	
	for(int j = 3; j <= 1010; j+= 2)
	if(chk[j] == 0)
	prime.push_back(j);	
}


void makeset(int n)
{
	par[n] = n;
	//rn[n] = 1;
}

int fnd(int r)
{
    if(par[r] == r) return r;
    else{
        return par[r] = fnd(par[r]);
    }
}

void unin(int a, int b)
{
	int u = fnd(a);
	int v = fnd(b);

	//cout << a << " " << u << " " << rn[u] << endl;
	//cout << b << " " << v << " " << rn[v] << endl;

	if(rn[u] > rn[v]){
	par[v] = u;
	}
	else{
		if(flag[u] == 1 && flag[v] == 1 ){
		par[v] = u;
		rn[u]++;
		}
		else if(flag[u] == 1){
			par[v] = u;
			rn[u]++;
		}
		else{
		par[u] = v;
		rn[v]++;	
		}
	}
}

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	/*7 3 19 18 6 14 11 2 16 11 17 13 13 10 14 16 6 9*/
	sieve();
	int test;
	
	scanf("%d", &test);
	int n;
	for(int tc = 1; tc <= test; tc++){
	scanf("%d", &n);
	memset(flag, 0, sizeof(flag));
	memset(rn, 0, sizeof(rn));
	
	for(int i = 0; i < n; i++){
	scanf("%d", &ara[i]);
	}
	
	for(int i = 0; i < n; i++){
	int m = ara[i];
	if(pf[m].size() == 0){
	for(int j = 0; prime[j] <= sqrt(m); j++){
		if(m % prime[j] == 0){
	//	cout <<ara[i] << " " <<  prime[j] << endl;
		pf[ara[i]].push_back(prime[j]);
		makeset(prime[j]);
		while(m % prime[j] == 0){
		m /= prime[j];
		}
		}
	}
	
	if(m > 1){
	pf[ara[i]].push_back(m);
	makeset(m);
}
}
}



for(int i = 0; i < n; i++){
		int v= ara[i];
	//	cout << v << endl;
		for(int k = 1; k < pf[v].size(); k++){
		unin(pf[v][k], pf[v][0]);
		flag[pf[v][k]] = 1;
		flag[pf[v][0]] = 1;
		//cout << pf[v][k] <<  endl;
	}
}

	set<int> ans;
	int cnt = 0;

	
for(int i = 0; i < n; i++){
		int v= ara[i];
		for(int k = 0; k < pf[v].size(); k++){
			par[pf[v][k]] = fnd(par[pf[v][k]]);
		}
	}
	
for(int i = 0; i < n; i++){
		int v= ara[i];
		for(int k = 0; k < pf[v].size(); k++){
		ans.insert(par[pf[v][k]]);
	//cout <<  pf[v][k] << " " << par[pf[v][k]] << endl;
		}
		if(ara[i] == 1)
		cnt++;
	}
	
	printf("Case %d: %d\n",tc, ans.size() + cnt);
	for(int i = 0; i < n; i++){
	pf[ara[i]].clear();
	}
	}
	return 0;
}
