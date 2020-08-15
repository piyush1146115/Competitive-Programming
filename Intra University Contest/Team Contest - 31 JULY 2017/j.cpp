#include<bits/stdc++.h>
using namespace std;
int ara[105];
struct st{
	int a, b, c;
};

int main()
{
	int test;
	scanf("%d", &test);
	
	for(int tc = 1; tc <= test; tc++){
		int n;
		scanf("%d", &n);
		
		for(int i = 0; i < n; i++)
		scanf("%d",&ara[i]);
		
		set< vector<int> > ss;
		//int cnt = 0;
		
		for(int i = 0; i < n - 2; i++){
			for(int j = i + 1; j < n -1; j++){
				for(int k = j + 1; k < n; k++){
					if(((ara[i] + ara[j]) > ara[k]) && ((ara[i] + ara[k]) > ara[j]) && ((ara[j] + ara[k]) > ara[i])){
						vector<int> v;
						v.push_back(ara[i]);
						v.push_back(ara[j]);
						v.push_back(ara[k]);
						sort(v.begin(), v.end());
						ss.insert(v);
					}
				}
			}
		}
		
		cout << "Case #" << tc << ": " << (int)ss.size() << endl;
		//mp.clear();
	}
	return 0;
}
