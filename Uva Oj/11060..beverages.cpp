#include<bits/stdc++.h>
using namespace std;
int taken[505], indegree[505];
int main()
{
   //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    string a, b, s;
    vector <int> lis, take[500];
    map <string, int> ma;
    map <int, string> m2;
    int i, j, m, n, k, t = 0;

    while(scanf("%d", &n) == 1){

            t++;
            memset(taken, 0, sizeof(taken));
            memset(indegree, 0, sizeof(indegree));

        for(i = 1; i <= n; i++){
            cin >> s;
            ma[s] = i;
            m2[i] = s;
        }

        cin >> m;

        for(i = 1; i <= m; i++){
            cin >> a >> b;
            take[ma[a]].push_back(ma[b]);
            indegree[ma[b]]++;
        }

        for(i = 1; i <= n; i++){
            for(j = 1; j <= n; j++){
                if( indegree[j] == 0 && taken[j] == 0){
                    taken[j] = 1;
                   lis.push_back(j);

                    for(k = 0; k < take[j].size(); k++){
                            --indegree[take[j][k]];
                    }
                    break;
                }
            }
        }

        printf("Case #%d: Dilbert should drink beverages in this order:", t);
        for(i = 0; i < lis.size(); i++){
            cout << " "<< m2[lis[i]];
        }
        printf(".\n\n");

        for(i = 0; i < 500; i++)
        take[i].clear();

        ma.clear();
        m2.clear();
        lis.clear();
    }
    return 0;
}
