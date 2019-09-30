/*
 * FILE: 1082 - Array Queries with segment trees.cpp
 *
 * @author: Piyush Kanti Das <piyush123kantidas[at]gmail[dot]com>
 *
 * LINK:
 *
 * DATE CREATED: 23.01.2018 10:38:30 +06
 *
 * DESCRIPTION:
 *
 * DEVELOPMENT HISTORY:
 * Date         Version     Description
 * --------------------------------------------------------------
 * 23-01-2018	1.0         File Created
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

#define fill(ar)   		memset(ar, -1, sizeof(ar))
#define clr(a)          memset(a, 0, sizeof(a))

#define nl              cout << '\n';
#define sp              cout << ' ';
#define ckk             cout << "##########\n"

#define pb              push_back
#define MP 				make_pair

#define debug1(x)       cerr << #x << ": " << x << endl
#define debug2(x, y)    cerr << #x << ": " << x << '\t' << #y << ": " << y << endl
#define debug3(x, y, z) cerr << #x << ": " << x << '\t' << #y << ": " << y << '\t' << #z << ": " << z << endl

#define gama 0.57721566490
#define PI              acos(-1.0)
#define INF             0x7fffffff
#define MOD             1000000007
#define EPS             1e-7
#define MAX             100005

ll BM( ll a , ll b , ll m )
{
    if ( b == 0 ) return 1 ;
    ll x = BM(a,b/2,m);
    x = (( x % m) * (x % m))%m;
    
    if( b % 2 ) x = (( x % m) * (a %m)) % m ;
    return x ;
}


/********************* Code starts here ************************/
int tree[MAX * 4 + 5], ara[MAX];

void init(int node, int b, int e)
{
	if(b == e){
		tree[node] = b;
		return;
	}
	
	init(node *2, b, (b + e)/2);
	init(node * 2 + 1, (b + e)/2 + 1, e);
	
	if(ara[tree[node * 2]] < ara[tree[node *2 +1]])
		tree[node] = tree[node * 2];
		else
		tree[node] = tree[node * 2 + 1];
	
	return;
}

int query(int node, int b, int e, int i, int j)
{
	if(b > j || e < i)
	return -1;
	
	//debug2(b, e );
	//getchar();
	
	if(b >= i && e <= j){
		return tree[node];
	}
	
	
	
	int p1 = query(node * 2 , b , (b + e)/2, i, j);
	int p2 = query(node * 2 + 1,  (b + e)/2 + 1, e, i, j);
	
	if(p1 == -1)
	return  p2;
	if(p2 == -1)
	return  p1;
	
	if(ara[p1] < ara[p2])
		return p1;
	else
	return p2;
}

int main(){
	
int test;
	scanf("%d", &test);
	
	for(int tc = 1 ;tc <=  test; tc++){
	int n, q;
	scanf("%d %d", &n , &q);
	
	for(int i = 1; i <= n; i++)
		scanf("%d", &ara[i]);
	
	init(1, 1, n);
	
	printf("Case %d:\n",tc);
	
	while(q--){
		int a, b;
		scanf("%d %d", &a, &b);
		int ans = query(1 , 1, n, a ,b);
		printf("%d\n",ara[ans]);
	}
}
    return 0;
}
