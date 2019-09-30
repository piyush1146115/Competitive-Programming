/*
 * FILE: test 2.cpp
 *
 * @author: Piyush Kanti Das <piyush123kantidas[at]gmail[dot]com>
 *
 * LINK:
 *
 * DATE CREATED: 03.07.2019 14:46:31 +06
 *
 * DESCRIPTION:
 *
 * DEVELOPMENT HISTORY:
 * Date         Version     Description
 * --------------------------------------------------------------
 * 03-07-2019	1.0         File Created
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

int Set(int N,int pos){return N=N | (1<<pos);}
int Reset(int N,int pos){return N= N & ~(1<<pos);}
bool Check(int N,int pos){return (bool)(N & (1<<pos));}


ll BM( ll a , ll b , ll m )
{
    if ( b == 0 ) return 1 ;
    ll x = BM(a,b/2,m);
    x = (( x % m) * (x % m))%m;
    
    if( b % 2 ) x = (( x % m) * (a %m)) % m ;
    return x ;
}

//Auto-format --> ctrl+shift+a
/********************* Code starts here ************************/

struct trie {
	trie *next[2];
	int cnt, num;
	trie() {
		next[0] = next[1] = NULL;
		cnt = num = 0;
	}
};

trie *root;

void insert(int x) {
	bitset<32> b(x);

	trie *cur = root;
	for(int i = 31, num; i >= 0; --i) {
		num = b[i];
		if(cur->next[num] == NULL)
			cur->next[num] = new trie();

		cur = cur->next[num];
		++cur->cnt;
	}

	cur->num = x;
}

void remove(int x) {
	bitset<32> b(x);

	trie *cur = root;
	for(int i = 31; i >= 0; --i) {
		cur = cur->next[b[i]];
		--cur->cnt;
	}
}

int find(int x) {
	bitset<32> b(x);

	trie *cur = root;
	for(int i = 31, num; cur != NULL && i >= 0; --i) {
		num = b[i];

		if(num == 0) {
			if(cur->next[1] != NULL && cur->next[1]->cnt > 0)
				cur = cur->next[1];
			else
				cur = cur->next[0];
		} else {
			if(cur->next[0] != NULL && cur->next[0]->cnt > 0)
				cur = cur->next[0];
			else
				cur = cur->next[1];
		}
	}

	if(cur == NULL)
		return x;
	return max(x ^ cur->num, x);
}

int q;

int main() {
	root = new trie();

	scanf("%d", &q);
	for(int i = 0; i < q; ++i) {
		char p;
		int x;
		scanf(" %c %d", &p, &x);

		if(p == '+')
			insert(x);
		else if(p == '-')
			remove(x);
		else
			printf("%d\n", find(x));
	}

	return 0;
}
