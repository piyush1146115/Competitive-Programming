#include<bits/stdc++.h>
using namespace std;
#define mxx 1000005

int f1[30], f2[30];

int main()
{
	string a , b;
	cin >> a >> b;
	
	int l1 = a.size();
	int l2 = b.size();
	
	int dif = 0;
	char ch;
	
	ch = ' ';
	a += '*';
	b += '*';
	
	vector<int> ans;
	int cnt = 0;
	
	for(int i = 0; i < l1; i++){
	
			if(a[i] == b[i]){
				if(a[i] == ch){
					cnt++;
					ans.push_back(i + 1);
				}
				else{
				ans.clear();
				cnt = 1;
				ans.push_back(i + 1);
				ch = a[i];	
				}
			}
			else{
				if(a[i] != ch)
				cnt = 0, ans.clear();
				cnt++;
				int j, k;
				for(j = i + 1, k = i; j < l1; j++, k++){
					
					if(a[j] != b[k]){
					cnt = 0;
					break;
				}
				}
				ans.push_back(i + 1);
				break;
			}
	}
	
	printf("%d\n",cnt);
	if(cnt != 0)
	printf("%d",ans[0]);
	for(int i = 1; i < (int)ans.size(); i++)
	printf(" %d",ans[i]);
	
	printf("\n");

//main();
}
