#include<bits/stdc++.h>
using namespace std;
#define mxx 10000005
#define ll long long 
ll status[mxx];
vector<ll>prime;

void sieve()
{
	long long int  i,j;
      
    
    for( i= 3;i  <= 10000000;i += 2){
        if(status[i]==0)
        {
			prime.push_back(i);
            for(j=i*i;j<=10000000;j+=(i * 2)){
                status[j]=1;
            }
        }
    }
  
    
    
   /* for(int i = 3; i <= 10000000; i+= 2)
    if(status[i] == 0)
    prime.push_back(i);*/
}

ll power(int b, int p)
{
	if(p == 0)
	return 1;
	if(p%2 == 0){
		ll res = power(b, p/2);
		return res * res;
	}
	else{
		return b * power(b, p- 1);
	}
}

int main()
{
	sieve();
	//cout << prime.size();
	int test;
	scanf("%d", &test);
	
	string s;
	for(int tc = 1; tc <= test; tc++){
		cin >> s;
		sort(s.begin(), s.end());
		//reverse(s.begin(), s.end());
		
		ll lo = 0;
		int flag[10];
		memset(flag, 0, sizeof(flag));
		
		for(int i = 0; i < (int)s.size(); i++){
			//cout << s[i] - '0' << endl;
			//cout << power(10, i) << endl;
			
			lo += ((s[i] - '0') * power(10, i));
			flag[s[i]- '0'] = 1;
		}
		//cout << lo <<" "  << s<<  endl;
		int cnt = 0;
		for(int i = 0; prime[i] <= lo; i++){
			
			ll n = prime[i];
			int res = 1;
			while(n != 0){
				ll k = n% 10;
				n/=10;
				if(flag[k] == 0){
					res = 0;
					break;
				}
			}
			if(res){
			cnt++;
			cout << prime[i] << endl;
		}
		}
		printf("%d\n",cnt);
	}
}
