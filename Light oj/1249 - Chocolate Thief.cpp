#include<bits/stdc++.h>
using namespace std;

struct st{
	string nam;
	int h, l, w, v;
}ara[105];

int main()
{
	int test;
	//scanf("%d",&test);
	cin >> test;
	for(int tc = 1; tc <= test; tc++){
		int n;
		//scanf("%d",&n);
		cin >> n;
		for(int i = 0; i < n; i++){
			cin >> ara[i].nam >> ara[i].h >> ara[i].l >> ara[i].w;
			ara[i].v = ara[i].h * ara[i].l * ara[i].w;
		}
		
		int mx = -1, num = 0;
		map<int, int> mp;
		int maxx = -1, minn = 10000000;
		for(int i = 0; i < n; i++){
			mp[ara[i].v]++;
			if(mp[ara[i].v] > mx){
				mx = mp[ara[i].v];
				num = ara[i].v;
			}
			maxx = max(maxx, ara[i].v);
			minn = min(minn , ara[i].v);
		}
		//printf("Case %d: ",tc);
		cout << "Case " << tc << ": ";
		if(mx == n){
			//printf("no thief\n");
			cout << "no thief\n";
		}
		else{
			string th, vic;
			
			
			for(int i = 0; i < n; i++){
				if(ara[i].v < num){
					vic = ara[i].nam;
				}
				if(ara[i].v > num){
					th = ara[i].nam;
				} 
			}
			
			if(mx == 1){
				for(int i = 0; i < n; i++){
				if(ara[i].v == minn){
					vic = ara[i].nam;
				}
				if(ara[i].v == maxx){
					th = ara[i].nam;
				} 
			}
			}
			cout <<th <<" took chocolate from " <<  vic << endl;
		}
	}
}
