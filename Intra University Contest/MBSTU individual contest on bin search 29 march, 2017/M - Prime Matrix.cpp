#include<bits/stdc++.h>
using namespace std;
#define mxx 100020
bool chk[mxx];
int next[mxx];
int mat[502][502];

void sieve()
{
    chk[1] = 1;

   for(int i =  4; i <= 100010; i += 2)
        chk[i] = 1;

   for(int i = 3; i * i <= 100010; i += 2){
    if(chk[i] == 0){
        for(int j = i * i; j <= 100010; j+= (i * 2)){
            chk[j] = 1;
        }
    }
   }

   int prime = 100003;

   for(int i = 100000; i >= 0; i--){
    if(chk[i] == 0)
        prime = i;

    next[i] = prime;
   }
}

int main()
{
    sieve();

    int n, m;

    scanf("%d %d", &n, &m);

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            scanf("%d", &mat[i][j]);
        }
    }
    int ans = 999999;
    for(int i = 0; i < n; i++){
            int res = 0;
        for(int j = 0; j < m; j++){
            res += abs(next[mat[i][j]] - mat[i][j]);
        }
    ans = min(res, ans);
    }

    for(int i = 0; i < m; i++){
            int res = 0;
        for(int j = 0; j < n; j++){
            res += abs(next[mat[j][i]] - mat[j][i]);
        }
        //cout << i << " " << res << endl;
    ans = min(res, ans);
    }

    printf("%d\n",ans);
/*
    for(int i = 1; i <= 10; i++)
        cout << prev[i] << " " << next[i] << endl;
        */
}
