#include<bits/stdc++.h>
using namespace std;

struct point{
double x, y;
};

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
point ara[105];
vector<edge> e;
int pr[105];

int findd(int r)
{
    return (pr[r] == r)? r : findd(pr[r]);
}

double mst(int n)
{
    for(int i = 0; i <= n; i++){
        pr[i] = i;
    }
    sort(e.begin(), e.end());
    int cnt = 0;
    double s = 0.0;

    for(int i = 0; i < e.size(); i++){
        int u = findd(e[i].u);
        int v = findd(e[i].v);

        if(u != v && cnt < n - 1){
            pr[u] = v;
            s += e[i].w;
            cnt++;
        }
    }
    return s;
}

int main()
{
    int test;
    scanf("%d", &test);
    while(test--){
        int n;
        scanf("%d", &n);

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

        double ans = mst(n);
        printf("%.2lf\n",ans);
        if(test)
            printf("\n");

        e.clear();
    }
    return 0;
}
