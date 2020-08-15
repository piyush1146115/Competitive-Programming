#include<bits/stdc++.h>
using namespace std;

struct st{
    int w, iq, indx;
}ara[1005];

int n;
int dp[1005], dir[1000];

int longest(int u)
{
    if(dp[u]!=-1) return dp[u];
	int maxi=0;

	for(int v = u+1;v < n;v++)
	{
		if(ara[v].w > ara[u].w && ara[v].iq < ara[u].iq)
		{
			if(longest(v)>maxi)
			{
				maxi=longest(v);
                dir[u]=v;
			}
		}
	}

	dp[u]=1+maxi;
	return 1 + maxi;
}

bool comp(st a, st b)
{
    if(a.w == b.w){
        if(a.iq > b.iq)
            return true;
        else
            return false;
    }
    if(a.w < b.w)
        return true;
    else
        return false;
}

int main()
{
    n = 0;
    int p, q;

    while(scanf("%d %d", &p, &q) == 2){
        ara[n].w = p;
        ara[n].iq = q;
        ara[n].indx = n + 1;
        n++;
    }

    sort(ara, ara  + n, comp);
//    for(int i = 0; i < n; i++)
//        printf("%d %d\n",ara[i].w, ara[i].iq);

    memset(dp, -1 , sizeof(dp));
    memset(dir, -1 , sizeof(dir));
    int ans = 0;
    int start = 0;

    for(int i = 0; i < n; i++){
        if(longest(i)> ans){
            start = i;
            ans = longest(i);
        }
    }
    printf("%d\n%d\n",ans, ara[start].indx);

    while(dir[start] != -1){
        printf("%d\n",ara[dir[start]].indx);
        start = dir[start];
    }

    return 0;
}
