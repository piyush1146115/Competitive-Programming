//#include<bits/stdc++.h>
//using namespace std;
//string s[1005];
//int dis[1005][1005];
//bool vis[1005][1005];
//int dx[] = {0, 0, -1, +1};
//int dy[] = {+1, -1, 0, 0};
//struct node{
//int x, y, v;
//};
//int n, m, k;
//
//bool valid(int x, int y)
//{
//    if(x >= 0 && y >= 0 && x < n && y < m  && s[x][y] == '.')
//        return true;
//
//    return false;
//}
//
//int bfs(int sx, int sy, int fx, int fy)
//{
//    queue<node> q;
//    node p;
//    p.x = sx;
//    p.y = sy;
//    p.v = 0;
//
//    q.push(p);
//    vis[sx][sy] = 1;
//
//    while(!q.empty())
//    {
//        p = q.front();
//        q.pop();
//        if(p.x == fx && p.y == fy){
//                //cout << xx << " " << yy << endl;
//            return p.v;
//        }
//
//        for(int i = 0; i < 4; i++)
//        {
//            for(int j = 1; j <= k; j++)
//            {
//                int x = p.x + (dx[i]*j);
//                int y = p.y + (dy[i]*j);
//                if(valid(x, y))
//                {
//                      if(vis[x][y] == 0)
//                    {
//                        vis[x][y] = 1;
//                       node pp;
//                       pp.x = x;
//                       pp.y = y;
//                       pp.v = p.v + 1;
//                       dis[x][y] = p.v + 1;
//                       q.push(pp);
//                    }
//                    else
//                    {
//                        if(dis[x][y] < p.v + 1)
//                        {
//                            break;
//                        }
//                    }
//                }
//                else
//                    break;
//            }
//        }
//    }
//    return -1;
//}
//
//int main()
//{
//
//
//    scanf("%d %d %d",&n, &m, &k);
//
//    for(int i = 0; i < n; i++)
//        cin >> s[i];
//
//
//    int x, y, x2, y2;
//
//    scanf("%d %d %d %d",&x, &y, &x2, &y2);
//
//    int ans = bfs(x - 1, y - 1, x2 -1, y2 - 1);
//
//    printf("%d\n",ans);
//
////    for(int i = 0; i < n; i++)
////        printf("%s\n",s[i]);
//
//}

#include<bits/stdc++.h>
using namespace std;
char s[1005][1005];
int dis[1005][1005];
bool vis[1005][1005];
int dx[] = {0, 0, -1, +1};
int dy[] = {+1, -1, 0, 0};

int n, m, k;

struct node{
int x, y, val;
};

bool valid(int x, int y)
{
    if(x < 0 || y < 0 || x >= n || y >= m ||vis[x][y] == 1 || s[x][y] == '#')
        return false;

    return true;
}

int bfs(int sx, int sy, int fx, int fy)
{
    if(sx == fx && sy == fy)
        return 0;

    queue<node> q;

    node p;
    p.x = sx;
    p.y = sy;
    p.val = 0;
    q.push(p);

    vis[sx][sy] = 1;

    while(!q.empty())
    {
        p = q.front();
        q.pop();
        if(p.x == fx && p.y == fy)
            return p.val;

        for(int i = 1; i <= k; i++)
        {
            int x = p.x + (dx[0] * i);
            int y = p.y + (dy[0] * i);
            if(valid(x, y))
            {
            vis[x][y] = 1;
                node pp;
                pp.x = x;
                pp.y = y;
                pp.val = p.val + 1;
                dis[x][y] = pp.val;
                q.push(pp);
            }
            else
                break;
        }

        for(int i = 1; i <= k; i++)
        {
            int x = p.x + (dx[1] * i);
            int y = p.y + (dy[1] * i);
            if(valid(x, y))
            {
            vis[x][y] = 1;
                node pp;
                pp.x = x;
                pp.y = y;
                pp.val = p.val + 1;
                dis[x][y] = pp.val;
                q.push(pp);
            }
            else
                break;
        }


        for(int i = 1; i <= k; i++)
        {
            int x = p.x + (dx[2] * i);
            int y = p.y + (dy[2] * i);
            if(valid(x, y))
            {
            vis[x][y] = 1;
                node pp;
                pp.x = x;
                pp.y = y;
                pp.val = p.val + 1;
                dis[x][y] = pp.val;
                q.push(pp);
            }
            else
                break;
        }


        for(int i = 1; i <= k; i++)
        {
            int x = p.x + (dx[3] * i);
            int y = p.y + (dy[3] * i);
            if(valid(x, y))
            {
            vis[x][y] = 1;
                node pp;
                pp.x = x;
                pp.y = y;
                pp.val = p.val + 1;
                dis[x][y] = pp.val;
                q.push(pp);
            }
            else
                break;
        }
    }
return -1;
}

int main()
{
    memset(dis, -1, sizeof(dis));

    scanf("%d %d %d",&n, &m, &k);

    for(int i = 0; i < n; i++)
        scanf("%s", &s[i]);

    int x, y, x2, y2;

    scanf("%d %d %d %d",&x, &y, &x2, &y2);

    int ans = bfs(x - 1, y - 1, x2 -1, y2 - 1);

    printf("%d\n",ans);

//    for(int i = 0; i < n; i++)
//        printf("%s\n",s[i]);

}
