#include<bits/stdc++.h>
using namespace std;
#define MX 1005
int row, col, dis[MX][MX], ara[MX][MX];

int fx[] = {+1, +0, -1, +0};
int fy[] = {+0, -1, +0, +1};

bool valid(int x, int y)
{
    if(x >= row || y >= col || x <0 || y < 0)
        return false;

    return true;
}

struct node{
    int x, y, cost;

    node(int _x, int _y, int _cost)
    {
        x = _x;
        y = _y;
        cost = _cost;
    }

};

bool operator < (node a, node b)
{
    return a.cost > b.cost;
}

void reset()
{
    for(int i = 0; i < row + 2; i++){
        for(int j = 0; j < col + 2; j++){
            dis[i][j] = INT_MAX;
        }
    }
}

void dijkstra()
{
    reset();
    dis[0][0] = ara[0][0];

    priority_queue<node> pq;

    pq.push(node(0, 0, ara[0][0]));

    while(!pq.empty()){
        node u = pq.top();
        pq.pop();

        if(u.cost != dis[u.x][u.y])
            continue;

            node v = u;

        for(int i = 0; i < 4; i++){
            v.x = u.x + fx[i];
            v.y = u.y + fy[i];

            if(valid(v.x, v.y)){
                if(dis[v.x][v.y] > u.cost + ara[v.x][v.y]){
                    dis[v.x][v.y] = u.cost + ara[v.x][v.y];
                    pq.push(node(v.x, v.y, dis[v.x][v.y]));
                }
            }
        }

    }
    return;
}

int main()
{
        int test, i, j, k;

        scanf("%d", &test);

        while(test--){
            scanf("%d %d", &row, &col);

            for(i = 0; i < row; i++){
                for(j = 0; j < col; j++){
                    scanf("%d",&ara[i][j]);
                }
            }

            dijkstra();

            printf("%d\n",dis[row - 1][col - 1]);
        }
        return 0;
}
