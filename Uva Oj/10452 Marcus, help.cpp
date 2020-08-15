#include<bits/stdc++.h>
using namespace std;

int dx[] = {-1, 0, 0};
int dy[] = {0, +1, -1};

/*
1
5 4
JA#X
JVBN
XOHD
DQEM
T@IY




6 5
PST#T
BTJAS
TYCVM
YEHOF
XIBKU
N@RJB
 */
 
string inp[15];
string s = "IEHOVA#";

int state, row, col;
vector<int> ans;

int vis[15][15];

void dfs(int sx, int sy)
{
    vis[sx][sy] = 1;
		
    for(int i = 0; i < 3; i++) {
        int tx = sx + dx[i];
        int ty = sy + dy[i];
        
        if(tx >= 0 && tx < row && ty >= 0 && ty < col && state < 7 && vis[tx][ty] == 0) {
            if(inp[tx][ty] == s[state]) {
                ans.push_back(i);
                state++;
                dfs(tx, ty);
                break;
            }
        }
    }
}

int main()
{
    int test;
    int sx, sy;

    scanf("%d", &test);

    while(test--) {

        memset(vis, 0, sizeof(vis));

        scanf("%d %d", &row, &col);

        for(int i = 0; i < row; i++) {
            cin >> inp[i];
        }

        for(int i = 0; i < row; i++) {
            for(int j = 0; j < col; j++) {
                if(inp[i][j] == '@')
                {
                    sx = i;
                    sy = j;
                }
            }
        }

        //cout << inp[sx][sy];

        state = 0;
        ans.clear();
        dfs(sx, sy);

        string st[3];

        st[0] = "forth";
        st[1] = "right";
        st[2] = "left";

        for(int i = 0; i < ans.size() - 1; i++)
        cout <<st[ans[i]] <<  " ";

        cout << st[ans[ans.size() - 1]] << endl;
    }
    return 0;
}
