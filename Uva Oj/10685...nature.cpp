#include<bits/stdc++.h>
using namespace std;
int rn[5500], par[5500];
map<string, int> m;

int fnd(int r)
{
    if(par[r] == r) return r;
    else{
        return par[r] = fnd(par[r]);
    }
}

void makeset(int n)
{
    par[n] = n;
}

void unin(int a, int b)
{
    int u = fnd(a);
    int v = fnd(b);
        if(u != v){
            if(rn[u] > rn[v]){
                par[v] = u;
            }
            else{
                par[u] = v;
                if(rn[u] == rn[v])
                    rn[v]++;
            }
        }
}


int main()
{
   // freopen("input.txt", "r", stdin);

    string s1, s2;
    int i, j, k, r, c, cn , mx;

    while(scanf("%d %d", &c, &r) == 2){

        if(r == 0 && c == 0)
            break;

        for(i = 1; i <= c; i++){
            cin >> s1;
            makeset(i);
            m[s1] = i;
        }

        for(i = 1; i <= r; i++){
            cin >> s1 >> s2;
            unin(m[s1], m[s2]);
        }
        mx = -1;
        for(i = 1; i < c; i++){
                cn = 0;
            for(j = i + 1; j <= c; j++){
                if(fnd(i) == fnd(j)){
                    cn++;
                }
            }
        mx = max(cn + 1, mx);
        }
        cout << mx << endl;
        m.clear();
    }
    return 0;
}
