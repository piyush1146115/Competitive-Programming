#include<bits/stdc++.h>
using namespace std;
#define mxx 200005

struct data{
	int a, b, dif;
	data(){}
	
	data(int x, int y, int z)
	{
		a = x;
		b = y;
		dif = z;
	}
}ara[mxx];

bool comp(data a, data b)
{
	return a.dif > b.dif;
}

int a[mxx], b[mxx];

int main()
{
	int n, k;
	
	scanf("%d %d", &n, &k);
	
	for(int i = 0; i < n; i++)
	scanf("%d", &a[i]);
	
	for(int i = 0; i < n; i++)
	scanf("%d",&b[i]);
	
	for(int i = 0; i < n; i++)
	{
		ara[i] = data(a[i], b[i], b[i] - a[i]);
	}
	
	sort(ara, ara + n, comp);
	
	long long sum = 0;
	
	for(int i = 0; i < k; i++)
	sum += ara[i].a;
	
	for(int i = k ; i < n; i++)
	sum += min(ara[i].a, ara[i].b);
	
	cout << sum << endl;
	
}
