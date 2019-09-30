#include<bits/stdc++.h>
using namespace std;
int par[30], rn[30], ans;

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
            ans--;
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
 int  x, y, n, i, test;
    string s, st;

    scanf("%d", &test);

    while(test--){
        cin>> s;
        getchar();
        n = s[0] - 64;
        memset(rn, 0, sizeof(rn));

        for(i = 1; i <= n; i++){
            makeset(i);
        }

        ans = n;

        while(getline(cin, s)){
            if(s.size() == 0){
                break;
            }

            x = s[0] - 64;
            y = s[1] - 64;
            unin(x, y);
        }

        cout << ans << endl;

        if(test)
            printf("\n");
    }
    return 0;
}
