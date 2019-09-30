#include<bits/stdc++.h>
using namespace std;
#define MAX 200005 
typedef long long ll;

struct task{
	ll tm, dead;
}ara[MAX];

bool comp(task a, task b)
{
	if(a.dead == b.dead)
		return a.tm < b.tm;
		
	return a.dead < b.dead;
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	
	ll n;
	cin >> n;
	
	for(int i = 0; i < n; i++){
		cin >> ara[i].tm >> ara[i].dead;
	}
		
	int flag = 1;
	sort(ara, ara + n, comp);
	
	ll sum = 0;
	for(int i = 0; i < n; i++){
		sum += ara[i].tm;
		if(ara[i].dead < sum){
			flag = 0;
			break;
		}
	}
	
	if(flag){
		cout << "Yes" << endl;
	}
	else{
		cout << "No" << endl;
	}
}
