#include<bits/stdc++.h>
using namespace std;

struct st {
    vector<int> v[15];
} ara[15];

int n, k, flag ;
int dp[15][1005];


int fun(int city, int day) {
    if (day == k) {
        if (city == n - 1) {
            flag = 1;
            return 0;
        }
         else
            return 1 << 30;

    }

    int ans = 1 << 30;

    if (day == k - 1) {
        if (city != n - 1 && ara[city].v[n - 1][day] > 0) {
            ans = ara[city].v[n - 1][day] + fun(n - 1, day + 1);
        }
        return ans;
    }
	
	if(dp[city][day] != -1)
	return dp[city][day];
	
    for (int i = 0; i < n; i++) {
        if (i == city)
            continue;

        if (ara[city].v[i][day] > 0)
            ans = min (ans, ara[city].v[i][day] + fun(i, day + 1));
    }

    return dp[city][day] = ans;
}


int main() {
	
	int tc = 0;
	
    while (scanf("%d %d", &n, &k) == 2) {
        if (n == 0 && k == 0)
            break;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i == j)
                    continue;
                int m;
                scanf("%d", &m);

                for (int x  = 0; x < m; x++) {
                    int dis;
                    scanf("%d", &dis);
                    ara[i].v[j].push_back(dis);
                }

                for (int x = m; x < k; x += m) {
                    for (int y = 0; y < m; y++) {
                        ara[i].v[j].push_back(ara[i].v[j][y]);
                    }
                }
            }
        }

        /*for(int i = 0; i < n; i++){
            for(int j = 0;j < n; j++){
                    printf("%d ----- %d \n",i,j);
                if(i == j)
                continue;
                for(int x = 0; x < ara[i].v[j].size(); x++)
                printf("day %d --- %d\n",x, ara[i].v[j][x]);
            }
        }*/

        flag = 0;
        memset(dp, -1, sizeof(dp));
        
        int ans = fun(0, 0);
			
		printf("Scenario #%d\n",++tc);
		
        if (flag == 0) {
            printf("No flight possible.\n\n");
        } else {
            printf("The best flight costs %d.\n\n", ans);
        }


        for (int i = 0; i < 12; i++) {
            for (int j = 0; j < 12; j++) {
                ara[i].v[j].clear();
            }
        }

    }
}
