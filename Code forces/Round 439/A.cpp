#include<bits/stdc++.h>
using namespace std;
#define ll long long 
int  a[2005], b[2005];
map<int , int> mp;

int main()
{
	int n;
	scanf("%d", &n);
	
	for(int i = 0; i < n; i++){
	scanf("%d", &a[i]);
	mp[a[i]] = 1;
}
	
	for(int j = 0; j < n; j++){
	scanf("%d",&b[j]);
	mp[b[j]] = 1;
}

ll cnt = 0;
for(int i = 0; i < n; i++){
	for(int j = 0; j < n; j++){
		int res = a[i] ^ b[j];
		if(mp.find(res) != mp.end())
		cnt++;
	}
}

if(cnt % 2 == 0)
printf("Karen\n");
else
printf("Koyomi\n");

}
