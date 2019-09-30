/*
 * FILE: B.cpp
 *
 * @author: Piyush Kanti Das <piyush123kantidas[at]gmail[dot]com>
 *
 * LINK:
 *
 * DATE CREATED: 03.12.2017 02:01:06 +06
 *
 * DESCRIPTION:
 *
 * DEVELOPMENT HISTORY:
 * Date         Version     Description
 * --------------------------------------------------------------
 * 03-12-2017	1.0         File Created
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

#define __FastIO        ios_base::sync_with_stdio(false); cin.tie(0)

#define forr(i, a, b)   for (__typeof (a) i=a; i<=b; i++)
#define rof(i, b, a)    for (__typeof (a) i=b; i>=a; i--)
#define rep(i, n)       for (__typeof (n) i=0; i<n; i++)
#define forit(i, s)     for (__typeof ((s).end ()) i = (s).begin (); i != (s).end (); ++i)
#define all(ar)         ar.begin(), ar.end()
#define fill(ar, val)   memset(ar, val, sizeof(ar))
#define clr(a)          memset(a, 0, sizeof(a))

#define nl              cout << '\n';
#define sp              cout << ' ';
#define ckk             cout << "##########\n"
#define pb              push_back
#define debug1(x)       cerr << #x << ": " << x << endl
#define debug2(x, y)    cerr << #x << ": " << x << '\t' << #y << ": " << y << endl
#define debug3(x, y, z) cerr << #x << ": " << x << '\t' << #y << ": " << y << '\t' << #z << ": " << z << endl

#define PI              acos(-1.0)
#define INF             0x7fffffff
//#define MOD             1000000000
#define EPS             1e-7
#define MAX             100005


/********************* Code starts here ************************/

ll ara[MAX];
ll MOD;
int main() {
    __FastIO;   //Be aware to use it!
    //cout << "Hello World!\n";
    int cnt = 0;
	ll inp, ans;
	cin >> inp >> MOD;
	
    for(int i = 1; i <= 9; i++){
		ara[++cnt] = ((i + i* 10) + ara[cnt - 1]) % MOD;
		//debug2(cnt, (i + i* 10));
		
	}
	
	for(ll i = 1; i <= 9; i++){
		for(ll j = 0; j <= 9; j++){
			ara[++cnt] = ((i * 1000 + j * 100 + j*10 + i) + ara[cnt - 1]) %MOD;
			
		}
	}
	
	for(ll i = 1; i <= 9; i++){
		for(ll j = 0; j <= 9; j++){
			for(ll k = 0; k <= 9; k++){
				ara[++cnt] = (ara[cnt - 1] + (i* 100000 + j * 10000 + k*1000 + k * 100 + j *10 + i))%MOD;
			}
		}
	}
	
	
	for(ll i = 1; i <= 9; i++){
		for(ll j = 0; j <= 9; j++){
			for(ll k = 0; k <= 9; k++){
				for(ll l = 0; l <= 9; l++){
				ara[++cnt] = (ara[cnt - 1] + (i* 10000000 + j * 1000000 + k*100000+ l*10000 + l *1000+k * 100 + j *10 + i)) % MOD;
				//debug2(cnt, ara[cnt]);
				//getchar();
			}
			}
		}
	}
	
	
	for(ll i = 1; i <= 9; i++){
		for(ll j = 0; j <= 9; j++){
			for(ll k = 0; k <= 9; k++){
				for(ll l = 0; l <= 9; l++){
					for(ll  m = 0; m <= 9; m++){
				ara[++cnt] = (ara[cnt - 1] + (i* 1000000000 + j * 100000000 + k* 10000000+ l*1000000 + m * 100000 + m*10000 + l *1000 +k*100 + j*10 + i)) %MOD;
				//debug2(cnt, ara[cnt]);
				//getchar();
			}
			}
			}
		}
	}
	ll flag = 0;
	for(ll i = 1; i <= 9; i++){
		for(ll j = 0; j <= 9; j++){
			for(ll k = 0; k <= 9; k++){
				for(ll l = 0; l <= 9; l++){
					for(ll  m = 0; m <= 9; m++){
						for(ll n = 0; n <= 9; n++){
				ara[++cnt] = (ara[cnt - 1] + (i* 100000000000 + j * 10000000000 + k*1000000000+ l*100000000 + m * 10000000 +n *1000000 +n*10000 + m*10000 + l *1000+k * 100 + j *10 + i) %MOD)%MOD;
				
				//debug2(cnt, ara[cnt]);
				//getchar();
				if(cnt >= 100000)
				{
					flag = 1;
					break;
				}
			}
			if(flag)
			break;
			}
			if(flag)
			break;
			}
			if(flag)
			break;
			}
			if(flag)
			break;
		}
		if(flag)
			break;
	}
	
//	debug2(cnt , ara[cnt]);

	cout << ara[inp] << endl;
    return 0;
}
