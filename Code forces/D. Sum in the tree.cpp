#include<bits/stdc++.h>
using namespace std;
#define MAX 100005
#define ll long long

vector<ll> tr[MAX];
ll val[MAX];
bool vis[MAX];
long long ans = 0, flag = 0;
void dfs(ll at, ll from, ll dep) {
    vis[at] = 1;
   
    if (dep % 2 == 0) {
		 ll mn = 1000000000000005;
        for (ll i = 0; i < (ll)tr[at].size(); i++) {
            ll v = tr[at][i];
            if (vis[v] == 0) {
                mn = min(mn, val[v]);
            }
        }

        if (mn < val[from]) {
            flag = 1;
            return;
        }else if(mn > 100000000000000){
			val[at] = 0ll;
			return;
		}
         else {
            val[at] = val[from] + (mn - val[from]);
            ans += (val[at] - val[from]);
        }
    } else {
        ans += (val[at] - val[from]);
    }


    for (ll i = 0; i < (ll)tr[at].size(); i++) {
        ll v = tr[at][i];
        if (vis[v] == 0) {
            dfs(v, at, dep + 1);
        }
    }
    return;
}

int main() {
    ll n, p;

    scanf("%lld", &n);
    for (ll i = 2; i <= n; i++) {

        scanf("%lld", &p);
        tr[p].push_back(i);
        tr[i].push_back(p);
    }

    for (ll i = 1; i <= n; i++) {
        scanf("%lld", &val[i]);
    }
	val[0] = 0;
    dfs(1ll, 0ll, 1ll);

    if (flag)
        ans = -1ll;

    cout << ans << endl;
}
