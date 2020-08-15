/*
 * FILE: J.cpp
 *
 * @author: Piyush Kanti Das <piyush123kantidas[at]gmail[dot]com>
 *
 * LINK:
 *
 * DATE CREATED: 16.01.2019 16:56:57 +06
 *
 * DESCRIPTION:
 *
 * DEVELOPMENT HISTORY:
 * Date         Version     Description
 * --------------------------------------------------------------
 * 16-01-2019   1.0         File Created
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


int T[MAX], R[MAX];
int len;
vll v;

int bin(int n) {
    int mid, lo = 0, hi = len;
    int ind = -1;

    while (lo <= hi) {
        mid = (lo + hi) / 2;
        if (v[T[mid]] >= v[n]) {
            ind = mid;
            hi = mid -1;
        } else {
            lo = mid + 1;
        }
        //debug3(n, mid,T[mid]);
         //debug1(ara[T[mid]]);
        //getchar();
    }
//	debug3(n, ara[n], ind);
	//forr(i, 0, len){
		//debug1(T[i]);
	//}
	//getchar();
    //ind = max(1, ind);
    return ind;

}

void LIS(int n) {
    forr(i, 1, n - 1) {
		
		if(v[i] > v[T[len]]){
			len++;
			T[len] = i;
			R[i] = T[len - 1];
			continue;
		}
		
		
		
        int ind = bin(i);
        
        //debug3(i, ind, len);
        //debug1(ara[i]);
        //getchar();
        
        if (ind == -1) {
            len++;
            T[len] = i;
            R[i] = T[len - 1];
          //  len++;
        } else {
            T[ind] = i;
            //ind = max(1, ind);
            if(ind != 0)
            R[i] = T[ind - 1];
        }
        //debug3(i, T[i], R[i]);
        //debug1(len);
        //getchar();
    }
}


int main() {
    //  __FastIO;   //Be aware to use it!

	ll n;
	fill(R);
	T[0] = len = 0;
	int cnt = 0;
	
	while(scanf("%lld", &n) == 1){
		cnt++;
		v.pb(n);
	}
	
	LIS(cnt);
	vll ans;
    int ind = T[len];
    
    ans.pb(v[T[len]]);
    while(R[ind] != -1){
		ans.pb(v[R[ind]]);
		ind = R[ind];
		
	}
	
	
	reverse(all(ans));
	//cout << len + 1ll << endl;
	printf("%d\n-\n",len + 1);
	rep(i, ans.size()){
		//cout << ans[i] << endl;
		printf("%lld\n",ans[i]);
	}
	
	
    return 0;
}
