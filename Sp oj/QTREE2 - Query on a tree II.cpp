#include <bits/stdc++.h>
using namespace std;
#define mxx 10005
#define ll long long
int N; //number of node
int L[mxx]; //level
int P[mxx][22]; // sparse table
int T[mxx]; //parent

ll dist[mxx];// distance
vector<int> g[mxx];
vector<int>cst[mxx];

void dfs(int from, int u, int dep, ll cost) {
    T[u] = from;
    L[u] = dep;
    dist[u] = cost;

    for (int i = 0; i < (int)g[u].size(); i++) {
        int v = g[u][i];

        if (v == from)
            continue;

        dfs(u, v, dep + 1, cost + cst[u][i]);
    }
}

int lca_query(int p, int q) {
    int  lg;

    if (L[p] < L[q])
        swap(p, q);

    lg = 1;

    while (1) {
        int next = lg + 1;
        if ((1 << next) > L[p])
            break;
        lg++;
    }

    for (int i = lg; i >= 0; i--) {
        if (L[p] - (1 << i) >= L[q]) {
            p = P[p][i];
        }
    }

    if (p == q)
        return p;

    for (int i = lg; i >= 0; i--) {
        if (P[p][i] != -1 && P[p][i] != P[q][i])
            p = P[p][i], q = P[q][i];
    }

    return T[p];
}

void lca_init() {
    memset(P, -1, sizeof(P));
    int i, j;

    for (i = 1; i <= N; i++) {
        P[i][0] = T[i];
    }

    for (j = 1; (1 << j) <= N; j++) {
        for (i = 1; i <= N; i++) {
            if (P[i][j - 1] != -1)
                P[i][j] = P[P[i][j - 1]][j - 1];
        }
    }
}

int ser(int p, int k) {
    int lg = 1;

    while (1) {
        if ((1 << lg) > L[p])
            break;
        lg++;
    }

    for (int i = lg; i >= 0; i--){
        if ((1 << i) <= k) {
            p = P[p][i];
            k -= (1 << i);
            if (k == 0)
                break;
        }
    }

    return p;
}

int main(){

    int test;
    scanf("%d", &test);

    while (test--) {
        scanf("%d", &N);

        for (int i = 1; i < N; i++) {
            int u, v, c;
            scanf("%d %d %d", &u, &v, &c);
            g[u].push_back(v);
            g[v].push_back(u);
            cst[u].push_back(c);
            cst[v].push_back(c);
        }
        dfs(1, 1, 0, 0);
        lca_init();

        string s;
        while (cin >> s) {
            if (s == "DONE")
                break;
            int u, v, k;

            if (s == "DIST") {
                scanf("%d %d", &u, &v);
                int lca = lca_query(u, v);
                ll res = (dist[u] - dist[1]) + (dist[v] - dist[1]) - (2 *(dist[lca] - dist[1]));
                printf("%lld\n", res);
            }
            if (s == "KTH") {
                scanf("%d %d %d", &u, &v, &k);
                int lca = lca_query(u, v);
                if (k <= (L[u] - L[lca] + 1)) {
                    int res = ser(u, k - 1);
                    printf("%d", res);
                } else if (k <= (L[u] - L[lca] + 1 + (L[v] - L[lca]))) {
                    int p = k - (L[u] - L[lca] + 1);
                    k = (L[v] - L[lca]) - p;
                    int res = ser(v, k);
                    printf("%d", res);
                }
                printf("\n");
            }
        }
        if (test) {
            printf("\n");
            for (int i = 0; i <= N; i++) {
                g[i].clear();
                cst[i].clear();
            }
        }
    }

}

