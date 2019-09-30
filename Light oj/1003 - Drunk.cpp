#include<bits/stdc++.h>
using namespace std;
#define mxx 20005

vector<int> take[mxx];
int taken[mxx], indegree[mxx];

int main()
{
    int test, tc = 0;
    map<string, int> mp;

    scanf("%d", &test);

    while(test--) {
        int m;
        scanf("%d", &m);

        int cnt = 0;

        memset(taken, 0 , sizeof(taken));
        memset(indegree, 0 , sizeof(indegree));

        while(m--) {

            string a, b;
            cin >> a >> b;

            if(mp[a] == 0)
                mp[a] = ++cnt;

            if(mp[b] == 0)
                mp[b] = ++cnt;

            take[mp[a]].push_back(mp[b]);
            indegree[mp[b]]++;

        }

        int n = cnt, j;
		int impos = 0;
		
		/*for(int i = 1; i <= n; i++)
		cout <<i << " " <<  indegree[i] << endl;
		*/
		
        for(int i = 1; i <= n ; i++) {
            for( j = 1; j <= n; j++){
				if(taken[j] == 0 && indegree[j] == 0)
				{
					taken[j] = 1;
					
					for(int k = 0; k < take[j].size(); k++)
					indegree[take[j][k]]--;
					
				
					break;
				}
            }
            if(j == n + 1)
            {
				impos = 1;
				break;
			}
        }
        
        if(impos == 1)
        printf("Case %d: No\n",++tc);
        else
        printf("Case %d: Yes\n", ++tc);
        
        for(int i = 0; i <= n ; i++)
        take[i].clear();
        
        mp.clear();
    }
    
    return 0;
    
}
