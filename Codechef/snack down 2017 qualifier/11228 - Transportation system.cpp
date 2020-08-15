#include<bits/stdc++.h>
using namespace std;

struct point{
double x, y;
};

double d, train, bus;
int cont;

struct edge{
int u, v;
double w;

bool operator < (const edge &p)const{
    return w < p.w;
}
};

double dist(point a, point b)
{
    return sqrt(abs((a.x - b.x)*(a.x - b.x)) + abs((a.y - b.y)*(a.y - b.y)));
}

point ara[1005];

vector<edge> e;
int pr[1005];

int findd(int r)
{
    return (pr[r] == r)? r : findd(pr[r]);
}

void mst(int n)
{
    train = 0.0;
    bus = 0.0;

    for(int i = 0; i <= n; i++){
        pr[i] = i;
    }

    sort(e.begin(), e.end());
    int cnt = 0;
    double s = 0.0;
        cont = 1;
    for(int i = 0; i < e.size(); i++){
        int u = findd(e[i].u);
        int v = findd(e[i].v);

        if(u != v && cnt < n - 1){
            pr[u] = v;
            if(e[i].w < d)
            bus += e[i].w;
            else{
            train += e[i].w;
            cont++;
            }
            cnt++;
        }
    }
}

int main()
{
    int test, tc = 0;
    scanf("%d", &test);
    while(test--){
        int n;
        scanf("%d %lf", &n, &d);

        for(int i = 0; i < n; i++){
            scanf("%lf %lf",&ara[i].x, &ara[i].y);
        }

        for(int i = 0; i < n; i++){
            for(int j = i + 1; j < n; j++){
                edge get;
                get.u = i + 1;
                get.v = j + 1;
                get.w = dist(ara[i], ara[j]);
                e.push_back(get);
            }
        }

        mst(n);
        int ans1, ans2;

        if((train - (int)train) >= 0.5)
            ans1 = (int)train + 1;
        else
            ans1 = (int)train;

        if((bus - (int)bus) >= 0.5)
            ans2 = (int)bus + 1;
        else
            ans2 = (int)bus;


        printf("Case #%d: %d %d %d\n",++tc, cont, ans2, ans1);
        e.clear();
    }
    return 0;
}
