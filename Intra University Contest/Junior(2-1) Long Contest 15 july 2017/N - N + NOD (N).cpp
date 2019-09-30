#include<bits/stdc++.h>
using namespace std;
#define pb push_back
bool ara[1050];
vector<int> prime, ans;

void sieve()
{
    int i, j;
    prime.pb(2);
    ara[1] = 1;

    for(i = 3; i <= 50; i += 2){
        if(ara[i] == 0){
            for(j = i * i; j <= 1020; j += i * 2)
            {
                ara[j] = 1;
            }
        }
    }

    for(j = 3; j <= 1020; j += 2)
    if(ara[j] == 0)
        prime.pb(j);
}

int nod(int n)
{
    int j , sum, cont;

            //k = sqrt(n);
            sum = 1;
            
            
        for(j = 0; prime[j] * prime[j] <= n; j++){
                cont = 0;
            while(n % prime[j] == 0){
                n /= prime[j] ;
                cont++;
            }
            sum *= (cont + 1);
        }
        
        if(n > 1)
            sum *= 2;
        
    return sum;
}

int main()
{
	sieve();
	
	int prev = 1, pres;
	ans.push_back(prev);
	
	while(prev <= 1000000){
	pres = prev + nod(prev);
	ans.push_back(pres);
	prev = pres;	
	}
	
	/*for(int i = 0; i < 100; i++)
	cout << ans[i] << " ";*/
	
	//cout << ans.size() << endl;
	
	int test;
	scanf("%d", &test);
	
	for(int tc = 1; tc <= test; tc++){
		int u, v;
		scanf("%d %d", &u, &v);
		
		if(u > v)
		swap(u, v);
		
		int lo = lower_bound(ans.begin(), ans.end(), u) - ans.begin();
		int up = upper_bound(ans.begin(), ans.end(), v) - ans.begin();
		
		printf("Case %d: %d\n",tc, (up - lo));
	}
}
