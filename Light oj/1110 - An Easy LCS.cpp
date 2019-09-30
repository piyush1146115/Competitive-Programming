#include<bits/stdc++.h>
using namespace std;

string a, b;
int dp[102][102];
vector<int> anxt[30], bnxt[30];
//int visit[102][102];

int lcs(int i, int j)
{
//    cout << i << " " << j << " " << a[i] << " " << b[j] << endl;
//    getchar();

    if(i == a.size() || j == b.size())
        return 0;

    if(dp[i][j] != -1)
        return dp[i][j];

    int ans = 0;

    if(a[i] == b[j])
    {
        ans = 1 + lcs(i + 1, j + 1);
    }
    else
    {
        ans = max(ans, lcs(i + 1, j));
        ans = max(ans, lcs(i, j + 1));
    }
    // visit[i][j] = 1;
    dp[i][j] = ans;

    return ans;
}

void adel(int pos)
{
    for(int i = 0; i < 26; i++){
        while(anxt[i].size() > 0 && anxt[i][0] <= pos){
            anxt[i].erase(anxt[i].begin());
        }
    }
}

void bdel(int pos)
{
   // cout << " ok " << endl;
    for(int i = 0; i < 26; i++){
            while(bnxt[i].size() > 0 && bnxt[i][0] <= pos ){
                bnxt[i].erase(bnxt[i].begin());
            }
    }

}

int res;
string ss, ans;

void path()
{
    for(int i = 0; i < 26; i++)
    {
        anxt[i].clear();
        bnxt[i].clear();
    }

    for(int i = 0; i < a.size(); i++){
            anxt[a[i] - 'a'].push_back(i);
            //cout << ch << " " << i << endl;
    }



    for(int i = 0; i < b.size(); i++){
            bnxt[b[i] - 'a'].push_back(i);
        //cout << ch << " " << i << endl;

    }


    for(int i = res ; i > 0; i--)
    {
        for(int j = 0; j < 26; j++){
            if(anxt[j].size() > 0 && bnxt[j].size() > 0){
                int p1 = anxt[j][0];
                int p2 = bnxt[j][0];
                if(dp[p1][p2] == i){
                    //cout << dp[p1][p2] << endl;
                    printf("%c", j + 'a');
                    //cout << p1 <<" " <<  p2 << " " << dp[p1][p2]<< endl;
                    adel(p1);
                    bdel(p2);
                    break;
                }
            }
        }
    }

}

int main()
{
    int test;
    scanf("%d", &test);

    for(int tc = 1; tc <= test; tc++)
    {
        cin >> a >> b;
        memset(dp, -1, sizeof(dp));

        res = lcs(0, 0);

        if(res == 0)
        {
            printf("Case %d: :(\n",tc);
        }
        else
        {
            printf("Case %d: ",tc);
            path();
            printf("\n");
        }
    }
    return 0;
}
