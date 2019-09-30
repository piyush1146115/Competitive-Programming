#include<bits/stdc++.h>
using namespace std;
int c;
vector <int> v[10005];
int ara[10005];
void f(int x){
    int i, j, k;
    for(i = 0; i < v[x].size(); i++){
        if(ara[v[x][i]] == 0){
            c++;
            ara[v[x][i]] = 1;
            f(v[x][i]);
        }
    }
    return;
}
int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int n, m, l, k, test, p, q, r, i, j;

    scanf("%d", &test);

    while(test--){
            memset(ara, 0, sizeof(ara));

        scanf("%d %d %d", &n, &m, &r);

        for(i = 0; i < m; i++){
            scanf("%d %d", &l ,&k);
            v[l].push_back(k);
        }
    c = 0;
       for(i = 0; i < r; i++){
        scanf("%d", &p);
        if(ara[p] == 0){
                c++;
                ara[p] = 1;
        }
        f(p);
        }
            printf("%d\n",min(c, n));
        for(i = 0; i < n; i++)
            v[i].clear();
    }
    return 0;
}
