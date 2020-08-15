#include<bits/stdc++.h>
using namespace std;

int dp[12][12][1005];
int ans[15];
int S, N, n;
map<int, int> chk;
int ara[15];


struct st {
    vector<int> v;
    int sz;
} inp[15];


bool comp(st a, st b) {
    if (a.sz < b.sz)
        return true;
    if (a.sz > b.sz)
        return false;

    for (int i = a.sz - 1; i >= 0; i--) {
        if (a.v[i] < b.v[i])
            return true;
           if(a.v[i] > b.v[i])
           return false;
    }
    return false;
}

void fun(int pos, int state, int value) {
    
    if (pos == n || state > S)
        return;

    
    chk[value] = 1;
    fun(pos + 1, state, value);
    fun(pos, state + 1, value + ara[pos]);
}


int main() {
    while (scanf("%d", &S) == 1) {

        memset(ans, 0, sizeof(ans));

        if (S == 0)
            break;

        scanf("%d", &N);

        for (int i = 0; i < N; i++) {
            int m;
            scanf("%d", &m);
            inp[i].sz = m;

            while (m--) {
                int temp;
                scanf("%d", &temp);
                inp[i].v.push_back(temp);
            }
        }
        sort(inp, inp + N, comp);

        /*for(int i = 0; i < N; i++){
          for(int j = 0; j < inp[i].v.size(); j++)
          cout << inp[i].v[j] << " ";

          cout << endl;
        }*/

       int mx = -999999;

        for (int i = 0; i < N; i++) {

            n = inp[i].sz;
            //memset(dp, -1, sizeof(dp));

            for (int j = 0; j < n; j++)
                ara[j] = inp[i].v[j];

            fun(0, 0, 0);
            int cnt = 0;

            for (int j = 1; ; j++) {
                if (chk[j] == 0)
                    break;
                cnt++;
            }
            //  cout << i << " " << cnt << endl;
            ans[i] = cnt;
            mx = max(mx, cnt);
            chk.clear();
        }

        for (int i = 0; i < N; i++) {
            if (ans[i] == mx) {
                printf("max coverage =%4d :", mx);

                for (int k = 0; k < inp[i].sz; k++)
                    printf("%3d", inp[i].v[k]);

                printf("\n");
                break;
            }
        }

        for (int i = 0; i <= N; i++) {
            inp[i].v.clear();
        }
    }
}
