/*
 * FILE: 1135 - Count the Multiples of 3.cpp
 *
 * @author: Piyush Kanti Das <piyush123kantidas[at]gmail[dot]com>
 *
 * LINK:
 *
 * DATE CREATED: 26.10.2018 01:07:03 +06
 *
 * DESCRIPTION:
 *
 * DEVELOPMENT HISTORY:
 * Date         Version     Description
 * --------------------------------------------------------------
 * 26-10-2018   1.0         File Created
 *
 */


/*
// _______________________________________________________________/\\\_________
//  ______________________________________________________________\/\\\_________
//   ___/\\\\\\\\\___/\\\____/\\\__/\\\____________________________\/\\\_________
//    __/\\\/////\\\_\///____\//\\\/\\\___/\\\____/\\\__/\\\\\\\\\\_\/\\\_________
//     _\/\\\\\\\\\\___/\\\____\//\\\\\___\/\\\___\/\\\_\/\\\//////__\/\\\\\\\\\\__
//      _\/\\\//////___\/\\\_____\//\\\____\/\\\___\/\\\_\/\\\\\\\\\\_\/\\\/////\\\_
//       _\/\\\_________\/\\\__/\\_/\\\_____\/\\\___\/\\\_\////////\\\_\/\\\___\/\\\_
//        _\/\\\_________\/\\\_\//\\\\/______\//\\\\\\\\\___/\\\\\\\\\\_\/\\\___\/\\\_
//         _\///__________\///___\////_________\/////////___\//////////__\///____\///__
//
*/

#include<bits/stdc++.h>
using namespace std;

typedef long long           ll;
typedef double              lf;
typedef unsigned long long  ull;
typedef pair<int, int>      pii;
typedef vector<pii>         vpii;
typedef vector<int>         vi;
typedef vector<long long>   vll;

#define __FastIO        ios_base::sync_with_stdio(false); cin.tie(0)

#define forr(i, a, b)   for (__typeof (a) i=a; i<=b; i++)
#define rof(i, b, a)    for (__typeof (a) i=b; i>=a; i--)
#define rep(i, n)       for (__typeof (n) i=0; i<n; i++)
#define forit(i, s)     for (__typeof ((s).end ()) i = (s).begin (); i != (s).end (); ++i)
#define all(ar)         ar.begin(), ar.end()

#define fill(ar)        memset(ar, -1, sizeof(ar))
#define clr(a)          memset(a, 0, sizeof(a))

#define nl              cout << '\n';
#define sp              cout << ' ';
#define ckk             cout << "##########\n"

#define pb              push_back
#define MP              make_pair

#define debug1(x)       cerr << #x << ": " << x << endl
#define debug2(x, y)    cerr << #x << ": " << x << '\t' << #y << ": " << y << endl
#define debug3(x, y, z) cerr << #x << ": " << x << '\t' << #y << ": " << y << '\t' << #z << ": " << z << endl

#define gama 0.57721566490
#define PI              acos(-1.0)
#define INF             0x7fffffff
#define MOD             1000000007
#define EPS             1e-7
#define MAX             100005

ll BM( ll a, ll b, ll m ) {
    if ( b == 0 ) return 1 ;
    ll x = BM(a, b / 2, m);
    x = (( x % m) * (x % m)) % m;

    if ( b % 2 ) x = (( x % m) * (a % m)) % m ;
    return x ;
}

//Auto-format --> ctrl+shift+a
/********************* Code starts here ************************/

struct data {
    int one, two, zero, prop;
};
data tree[MAX * 4];

data combine(data a, data b) {
    data ret;
    ret.prop = 0;
    ret.zero = a.zero + b.zero;
    ret.one = a.one + b.one;
    ret.two = a.two + b.two;

    return ret;
}

void push(int v,int sum) {
    if (sum) {
        data temp = tree[v];

        if (sum % 3 == 1) {
            tree[v].zero = temp.two;
            tree[v].one = temp.zero;
            tree[v].two = temp.one;
        } else if (sum % 3 == 2) {
            //debug1(tree[v].prop);
            tree[v].one = temp.two;
            tree[v].zero = temp.one;
            tree[v].two = temp.zero;
        }
    }
  
}

void build(int v, int tl, int tr) {
    if (tl == tr) {
        tree[v].zero = 1;
        tree[v].one = tree[v].two = tree[v].prop = 0;
    } else {
        int tm = (tl + tr) / 2;
        build(v * 2, tl, tm);
        build(v * 2 + 1, tm + 1, tr);

        tree[v] = combine(tree[v * 2], tree[v * 2 + 1]);
    }
}




void update(int v, int tl, int tr, int l, int r) {
    if (l > tr || r < tl)
        return;
    if (tl >= l && tr <= r) {
        tree[v].prop++;
        push(v, 1);
        return;
    }
    tree[v * 2].prop += tree[v].prop;
    tree[v * 2 + 1].prop += tree[v].prop;
    //tree[v].prop = 0;
    push(v * 2, tree[v].prop);
    push(v * 2 + 1, tree[v].prop);
	tree[v].prop = 0;
	
    int tm  = (tl + tr) / 2;
    update(v * 2, tl, tm, l, r);
    update(v * 2 + 1, tm + 1, tr, l, r);
    tree[v] = combine(tree[v * 2], tree[v * 2 + 1]);
}

int query(int v, int tl, int tr, int l, int r) {
    if (l > tr || r < tl)
        return 0;
    
    if (tl >= l && tr <= r) {
        //debug3(tl, tr, tree[v].zero);
        //debug2(tree[v].one, tree[v].two);
        return tree[v].zero;
    }
	tree[v * 2].prop += tree[v].prop;
    tree[v * 2 + 1].prop += tree[v].prop;
    //tree[v].prop = 0;
    push(v * 2, tree[v].prop);
    push(v * 2 + 1, tree[v].prop);
	tree[v].prop = 0;
    int tm = (tl + tr) / 2;
    return query(v * 2, tl, tm, l, r) + query(v * 2 + 1, tm + 1, tr, l, r);
}

int main() {
    //  __FastIO;   //Be aware to use it!
    int test;
    scanf("%d", &test);

    forr(tc, 1, test) {
        int n, q;

        scanf("%d %d", &n, &q);
        printf("Case %d:\n", tc);
        build(1, 1, n);
        while (q--) {
            int tpe, l, r;
            scanf("%d %d %d", &tpe, &l, &r);
            if (tpe == 0) {
                update(1, 1, n, l + 1, r + 1);
            } else {
                int ans = query(1, 1, n, l + 1, r + 1);
                printf("%d\n", ans);
            }
        }
    }
    return 0;
}
