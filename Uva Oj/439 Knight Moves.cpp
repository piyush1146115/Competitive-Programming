#include<bits/stdc++.h>
using namespace std;

bool vis[15][15];
int cost[15][15], dis[3];

int fx[] = {+2, +2, +1, -1, -2, -2, -1, +1};
int fy[] = {-1, +1, +2, +2, +1, -1, -2, -2};

bool valid(int x, int y)
{
    if(x < 0 || y < 0 || x >= 8 || y >= 8 || vis[x][y] == 1 )
        return false;
    else
        return true;
}

void reset()
{
    for(int i = 0; i <= 12; i ++){
        for(int j = 0; j <= 12 ; j++){
            cost[i][j] = 0;
            vis[i][j] = 0;
        }
    }
}

int bfs(int sx, int sy)
{

    queue<pair<int, int> > q;

    q.push({sx, sy});
    cost[sx][sy] = 0;
    vis[sx][sy] = 1;

    if(sx == dis[0] && sy == dis[1])
        return 0;

    while(!q.empty()){
        pair<int, int> u;

        u = q.front();
        q.pop();

        int  ux = u.first;
        int uy = u.second;

        for(int i = 0; i < 8; i++){
            int vx = ux + fx[i];
            int vy = uy + fy[i];

        if(valid(vx, vy)){

            cost[vx][vy] = cost[ux][uy] + 1;
            vis[vx][vy] = 1;

              if(vx == dis[0] && vy == dis[1])
                    return cost[vx][vy];

            q.push({vx, vy});
        }
    }
}

}

int main()
{
    string sou, des;
    int ans, j, k;

    while(cin >> sou >> des)
    {
        reset();
        dis[0] = des[1] - 49;
        dis[1] = des[0] - 97;
        ans = bfs(sou[1] - 49, sou[0] - 97);

//        cout << ans << endl;
    cout << "To get from " << sou <<" to " <<des << " takes " << ans <<" knight moves.\n" ;
    }

    return 0;
}
