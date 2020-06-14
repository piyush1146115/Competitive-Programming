#include<cstdio>
#include<sstream>
#include<cstdlib>
#include<cctype>
#include<cmath>
#include<algorithm>
#include<set>
#include<queue>
#include<stack>
#include<list>
#include<iostream>
#include<fstream>
#include<numeric>
#include<string>
#include<vector>
#include<cstring>
#include<map>
#include<iterator>
using namespace std;
#define mxx 100005
bool articulation_point[mxx];
bool visited[mxx];
int low[mxx], d[mxx], parent[mxx] ,no_of_chil ;
int time = 0;
vector <int>  g[mxx];

void reset()
{
for(int i = 0 ; i < mxx; i++)
{
	parent[i] = i;
	time = 0;
	no_of_chil = 0;
}	
}

void find(int u)
{

	time++;
	low[u] = d[u] = time;
	
	visited[u] = 1;
	//no_of_chil[u] = 0;
		for(int i = 0; i < g[u].size(); i++){
		int v = g[u][i];
		
		if(v == parent[u])
		{
			continue;
		}
		if(!visited[v]){
			parent[u] = v;
		
		find(v);
		
		low[u] = min(low[u], low[v]);
		
		if(d[u] <= low[v] && parent[u] != u) {
			articulation_point[u] = true;
		}
		no_of_chil++;
	}
	
	if(no_of_chil > 1 && parent[u] == u)
		{
			articulation_point[u] = true;
		}
}
}

int main()
{
int a, b;
scanf("%d %d", &a, &b);	
}
