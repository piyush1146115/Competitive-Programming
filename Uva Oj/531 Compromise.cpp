#include<bits/stdc++.h>
using namespace std;
vector<string> a, b;
int dp[105][105];
int res;
int lcs(int i, int j)
{
    if(i == a.size() || j == b.size())
        return 0;
    int ans = 0;
    if(dp[i][j] != -1)
        return dp[i][j];

    if(a[i] == b[j]){
        ans = 1 + lcs(i + 1, j + 1);
    }
    else{
        ans = max(ans, lcs(i + 1, j));
        ans = max(ans, lcs(i , j + 1));
    }
    return dp[i][j] = ans;

}

void path(int i, int j)
{
    if(i == a.size() || j == b.size())
        return;
    if(a[i]== b[j]){
        res--;

            cout << a[i];

            if(res > 0)
                cout << " ";

        path(i + 1, j + 1);
    }
    else{
        int r1 = lcs(i, j + 1);
        int r2 = lcs(i + 1, j);

        if(r1 > r2)
            path(i, j + 1);
        else
            path(i + 1 , j);
    }

}
int main()
{

    string s;

    while(cin >> s){

        if(s != "#"){
            a.push_back(s);
            continue;
        }

        while(cin >> s){
            if(s == "#")
                break;
            b.push_back(s);
        }
        memset(dp, -1, sizeof(dp));

        res = lcs(0, 0);
        path(0, 0);
        //cout << ans << endl;
        printf("\n");
        a.clear();
        b.clear();
    }
}
