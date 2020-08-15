#include<bits/stdc++.h>
using namespace std;
#define ll long long
string s[25];
int dp[5][30];

int n, m, v;

int fun(int state, int pos)
{

    int p = 0,  ret1 , ret2;
    if(pos == v){
        if(state == 0){
        for(int i = 1; i <= m; i++){
            if(s[pos][i] == '1'){
                p = i;
            }
        }
        return p;
        }
        else{
        for(int i = m; i >= 1; i--){
            if(s[pos][i] == '1'){
                p = i;
            }
        }
        return (m+ 1 - p);
        }
    }

    if(state == 0){
        for(int i = 1; i < m + 2; i++){
            if(s[pos][i] == '1'){
                p = i;
            }
        }
        if( p == 0)
        {
        ret1 =  1 + fun(state, pos - 1);
        ret2 =  m + 2 +  fun(0, pos - 1);
        }
        else{
        ret1 = (p * 2) + 1 +  fun(state, pos - 1);
        ret2 = m  + 2 + fun(1, pos - 1);
        }
    }

    if(state == 1){
        for(int i = m; i >= 1; i--){
            if(s[pos][i] == '1'){
                p = i;
            }
        }
        if( p == 0)
        {
        ret1 =  1 + fun(state, pos - 1);
        ret2 =  m + 2 +  fun(0, pos - 1);
        }
        else{
        ret1 = ((m + 1 - p) * 2)  + 1 + fun(state, pos - 1);
        ret2 = m  + 2 +  fun(0, pos - 1);
        }
    }
    return min(ret1, ret2);
}

int main()
{
    //memset(dp, -1, sizeof(dp));

    scanf("%d %d",&n, &m);

    for(int i = 0; i < n; i++){
        cin >> s[i];
    }
    v = n - 1;
    for(int i = n - 1; i >=  0; i--){
        for(int j = 0; j < m +2; j++){
            if(s[i][j] == '1')
                v = i;
        }
    }
    //cout << "ok" << endl;
  printf("%d\n", fun(0, n - 1));
}
