#include <bits/stdc++.h>
using namespace std;
#define mxx 5005
#define ll long long
int N; //number of node
int L[mxx]; //level
int P[mxx][22]; // sparse table
int T[mxx]; //parent
vector<int> g[mxx];


void dfs(int from, int u, int dep)
{
    T[u] = from;
    L[u] = dep;


    for (int i = 0; i < (int)g[u].size(); i++)
    {
        int v = g[u][i];

        if (v == from)
            continue;

        dfs(u, v, dep + 1);
    }
}

int lca_query(int p, int q)
{
    int  lg;

    if (L[p] < L[q])
        swap(p, q);

    lg = 1;

    while (1)
    {
        int next = lg + 1;
        if ((1 << next) > L[p])
            break;
        lg++;
    }

    for (int i = lg; i >= 0; i--)
    {
        if (L[p] - (1 << i) >= L[q])
        {
            p = P[p][i];
        }
    }

    if (p == q)
        return p;

    for (int i = lg; i >= 0; i--)
    {
        if (P[p][i] != -1 && P[p][i] != P[q][i])
            p = P[p][i], q = P[q][i];
    }

    return T[p];
}

void lca_init()
{
    memset(P, -1, sizeof(P));
    int i, j;

    for (i = 1; i <= N; i++)
    {
        P[i][0] = T[i];
    }

    for (j = 1; (1 << j) <= N; j++)
    {
        for (i = 1; i <= N; i++)
        {
            if (P[i][j - 1] != -1)
                P[i][j] = P[P[i][j - 1]][j - 1];
        }
    }
}

int ser(int p, int k)
{
    int lg = 1;

    while (1)
    {
        if ((1 << lg) > L[p])
            break;
        lg++;
    }

    for (int i = lg; i >= 0; i--)
    {
        if ((1 << i) <= k)
        {
            p = P[p][i];
            k -= (1 << i);
            if (k == 0)
                break;
        }
    }

    return p;
}

int main()
{

    while (scanf("%d", &N) == 1)
    {
        if(N == 0)
            break;

        for (int i = 1; i < N; i++)
        {
            int u, v;
            scanf("%d %d", &u, &v);
            g[u].push_back(v);
            g[v].push_back(u);
        }

        dfs(1, 1, 0);
        lca_init();

        int l;
        scanf("%d", &l);

        while (l--)
        {

            int u, v, k;
            scanf("%d %d", &u, &v);

            int lca = lca_query(u, v);
            int dif = (L[u] - L[lca]) + (L[v] - L[lca]);


            if(dif % 2 != 0)
            {

                int k1 = dif/2;
                int k2 = dif/2 + 1;
                int r1, r2;
				//cout << "lca" << " " << lca << " Level[lca] " << L[lca] <<  endl;
				 
                if (k1 <= (L[u] - L[lca]))
                {
                    r1 = ser(u, k1);
                }
                else
                {
                    int p = k1 - (L[u] - L[lca]);
                    k1 = (L[v] - L[lca]) - p;
                     r1 = ser(v, k1);
                }

                if (k2 <= (L[u] - L[lca]))
                {
                     r2 = ser(u, k2);
                }
                else
                {
                    int p = k2 - (L[u] - L[lca]);
                    k2 = (L[v] - L[lca]) - p;
                     r2 = ser(v, k2);

                }
                if(r1 > r2)
                    swap(r1, r2);

                printf("The fleas jump forever between %d and %d.\n",r1, r2);
            }
            else
            {
                k = dif/2;

                if (k <= (L[u] - L[lca]))
                {
                    int res = ser(u, k);
                    printf("The fleas meet at %d.\n", res);
                }
                else
                {
                    int p = k - (L[u] - L[lca]);
                    k = (L[v] - L[lca]) - p;
                    int res = ser(v, k);
                    printf("The fleas meet at %d.\n", res);
                }
             

            }
        }
        for (int i = 0; i <= N; i++)
        {
            g[i].clear();
        }

    }
}

