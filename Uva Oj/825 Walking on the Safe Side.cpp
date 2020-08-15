#include<bits/stdc++.h>
using namespace std;
#define mxx 505
int  safe[mxx][mxx], dp[mxx][mxx] , row, col;

bool valid()
int fun(int x, int y)
{
    if(x == row && y == col)
        return 0;

    if(dp[x][y] != -1)
        return dp[x][y];

    int ans = 1 << 30;

    if(valid(x + 1, y + 1))
}
int main()
{
   int test;

   scanf("%d", &test);

   while(test--){
    scanf("%d %d", &row, &col);

    memset(dp, -1, sizeof(dp));
    memset(safe, 0, sizeof(safe));

    for(int i = 0; i < row; i++){
        int r, c;
        scanf("%d", &r);
        getchar();
        string s;
        getline(cin , s);
        stringstream ss(s);

        while(ss >> c){
            safe[r][c] = 1;
        }
    }
   }
}
