#include<bits/stdc++.h>
using namespace std;
#define MAX 1005
string s;
int PAL[MAX][MAX], DP[MAX];

bool pal(int l, int r)
{

    if(l > r)
        return false;

        if(PAL[l][r] != -1){
            return PAL[l][r];
        }

    while(l <= r){
        if(s[l] != s[r]){
            return 0;
        }
        l++;
        r--;
    }
    return 1;
}

int fun(int pos)
{
    if(pos >= s.size()){
        return 0;
    }

    if(DP[pos] != -1){
        return DP[pos];
    }

    int ret = 10000000;
    for(int i = pos; i < s.size(); i++){
        if(pal(pos,i)){
            ret = min(ret, 1 + fun(i + 1));
        }
    }
    DP[pos]= ret;
    return ret;
}

int main()
{
        int test;
        scanf("%d", &test);

        for(int tc = 1; tc <= test; tc++){
            memset(PAL, -1, sizeof(PAL));
            memset(DP, -1, sizeof(DP));

            cin >> s;

            int ans = fun(0);

            printf("Case %d: %d\n",tc, ans);
        }
}
