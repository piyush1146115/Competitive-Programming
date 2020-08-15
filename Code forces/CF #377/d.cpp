#include<bits/stdc++.h>
using namespace std;
#define MX 100006
int ara[MX], d[MX];
bool vis[MX];

bool khoj(int ed, int m)
{
    int i, j, k;

    memset(vis, 0, sizeof(vis));

    int sum = 0;

    for(i = ed;i >= 1; i--){
        if(vis[ara[i]] == 0 && ara[i]){

            vis[ara[i]] = 1;
            if(i < d[ara[i]])
                return 0;

             sum -= d[ara[i]];
        }
        else
            sum++;
    }

    if(sum < 0)
        return 0;

    for(int i = 1; i <= m; i++)
        if(!vis[i])
        return 0;

    return 1;
}

int main()
{
    int i, j, k, n, m;

    cin >> n >> m;

    for(i = 1; i <= n; i++)
        scanf("%d",&ara[i]);

    for(i = 1; i <= m; i++)
        scanf("%d",&d[i]);

    int ans = -1, mid, lo, hi;

    lo = 1;
    hi = n;

    while(lo <= hi){
        mid = (lo + hi) / 2;

        if(khoj(mid, m)){
            hi = mid - 1;
            ans = mid;
        }
        else{
            lo = mid + 1;
        }
    }

    cout << ans << endl;

}
