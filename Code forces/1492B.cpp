#include<bits/stdc++.h>
using namespace std;
 
#define MAX 100005
 
int v[MAX], mx[MAX];
 
int main()
{
	ios_base::sync_with_stdio(false);
	
	int test;
	cin >> test;
	
	while(test--){
	
	
	int n;
	cin >> n;
	
	
	
	
	int maxx = 0;
	
	for(int i = 0; i < n ; i++){
		cin >> v[i];
		maxx = max(maxx, v[i]);
		//cout << v[i] << endl;
		mx[i] = maxx;
	}
	
	
	vector<int> ans;
	
	stack<int> st;
	
	for(int i = n  - 1; i >= 0; i--){
		st.push(v[i]);
		
		if(v[i] == mx[i]){
			while(!st.empty()){
				ans.push_back(st.top());
				st.pop();
			}
		}
	}
	
	while(!st.empty()){
				ans.push_back(st.top());
				st.pop();
			}
	
	
	for(int i = 0; i < n; i++)
		cout << ans[i] << ' ';
	
	cout << endl;
}
	
}
