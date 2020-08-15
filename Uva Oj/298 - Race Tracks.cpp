#include<bits/stdc++.h>
using namespace std;
#define cons 5

bool grid[35][35];
int vis[35][35][15][15];
int NX, NY;

struct st
{
    int xx, yy, sx, sy;
};

struct point
{
    int x , y;
};

point srt, fin;

bool valid(st s)
{
    if(s.xx < NX && s.yy < NY && s.xx >= 0 && s.yy >= 0 && vis[s.xx][s.yy][s.sx + cons][s.sy + cons] == -1 && grid[s.xx][s.yy] == 0)
    {
        return true;
    }
    else
        return false;
}



int bfs()
{

    queue<st> q;
    st u;
    u.xx = srt.x;
    u.yy = srt.y;
    u.sx = 0;
    u.sy = 0;

    vis[u.xx][u.yy][u.sx + cons][u.sy + cons] = 0;

    if(u.xx == fin.x && u.yy == fin.y)
        return 0;

    q.push(u);
   // cout << u.xx << " " << u.yy << " " << u.sx << " " << u.sy << endl;

    while(!q.empty())
    {
        u = q.front();
        q.pop();

        for(int i = -1; i <= 1; i++)
        {
            for(int j = -1; j <= 1; j++)
            {
                st v;
                v.sx = u.sx + i;
                v.sy = u.sy + j;
                v.xx = u.xx + v.sx ;
                v.yy = u.yy + v.sy;
                if(v.sx < -3 || v.sy < -3 || v.sx > 3 || v.sy > 3)
                    continue;
//
//                    cout << v.xx << " " << v.yy << " " << v.sx << " " << v.sy <<" " << vis[v.xx][v.yy][v.sx + cons][v.sy + cons] << endl;
//                    getchar();

                if(valid(v))
                {
                    vis[v.xx][v.yy][v.sx + cons][v.sy + cons] =1 + vis[u.xx][u.yy][u.sx+ cons][u.sy + cons];
                    if(v.xx == fin.x && v.yy == fin.y)
                        return vis[v.xx][v.yy][v.sx + cons][v.sy + cons];

                    q.push(v);
                }
            }
        }
    }
    return 999999;
}



int main()
{
    int test;

    scanf("%d",&test);

    while(test--)
    {
        scanf("%d %d", &NX, &NY);
        scanf("%d %d %d %d",&srt.x, &srt.y, &fin.x, &fin.y);
        int m;
        scanf("%d",&m);
        memset(vis, -1, sizeof(vis));
        memset(grid, 0, sizeof(grid));

        while(m--)
        {
            int x1, x2, y1, y2;
            scanf("%d %d %d %d",&x1, &x2, &y1,&y2);

            for(int i = x1; i <= x2; i++)
            {
                for(int j = y1; j <= y2; j++)
                {
                    grid[i][j]= 1;
                }
            }

        }

        int ans = bfs();

        if(ans == 999999)
        {
            printf("No solution.\n");
        }
        else
        {
            printf("Optimal solution takes %d hops.\n",ans);
        }
    }
}
