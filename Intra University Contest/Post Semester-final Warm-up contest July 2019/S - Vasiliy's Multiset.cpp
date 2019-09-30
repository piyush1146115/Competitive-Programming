/*
 * FILE: S - Vasiliy's Multiset.cpp
 *
 * @author: Piyush Kanti Das <piyush123kantidas[at]gmail[dot]com>
 *
 * LINK:
 *
 * DATE CREATED: 03.07.2019 12:55:55 +06
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
bool Check(ll N,ll pos){return (bool)(N & (1LL<<pos));}


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

struct node{
	int cnt;
	ll num;
	node *next[2];
	node(){
		cnt = 0;
		num = 0LL;
		next[0] = NULL;
		next[1] = NULL;
	}
};

node *root;


void insert(ll num)
{
	node *curr = root;
	int id;
	for(ll i = 31; i >= 0; i--){
	if(Check(num,i)){
			id = 1;
		}else{
			id = 0;
		}
	//	debug3(i, id, num);
		
		if(curr->next[id] == NULL)
			curr->next[id] = new node();
			
		curr = curr->next[id];
		++curr->cnt;
	}
	curr->num = num;
}

void remove(ll num)
{
	node *curr = root;
	int id;
	for(ll i = 31; i >= 0; i--){
		if(Check(num,i)){
			id = 1;
		}else{
			id = 0;
		}
		curr = curr -> next[id];
		--curr -> cnt;
	}
}

ll query(ll x)
{
	node *curr = root;
	ll ans = 0;
	for(ll i = 31; i >= 0; i--){
		if(Check(x,i) == false){
			if(curr -> next[1] != NULL && curr -> next[1]->cnt > 0){
				curr = curr -> next[1]; 
			}else{
				curr = curr->next[0];
			}
			
		}else{
			if(curr -> next[0] != NULL && curr->next[0]->cnt > 0){
				curr = curr->next[0]; 
			}else{
				curr = curr -> next[1];
			}
		}
	}
	if(curr== NULL)
	return x;
	
	ans = x^curr->num;
	ans = max(ans, x);
	return ans;
}

/*void del(node *cur)
{
	if(cur -> next[0])
	del(cur -> next[0]);
	
		if(cur -> next[1])
	del(cur -> next[1]);

delete(cur);
}
*/
int main() {
	
	root = new node();
    int q;
    scanf("%d" , &q);
   // getchar();
    insert(0LL);
    
    while(q--){
		char ch;
		ll num;
		scanf(" %c %lld", &ch, &num);
		//debug2(ch, num);
		if(ch == '+'){
			insert(num);
		}else if(ch == '-'){
			remove(num);
		}
		else{
			ll ans = query(num);
			printf("%lld\n",ans);
		}
	}
	//del(root);
    return 0;
}
/*
10
? 1
+ 1
+ 8
- 1
+ 2
+ 7
+ 4
+ 7
+ 3
? 7
*/

