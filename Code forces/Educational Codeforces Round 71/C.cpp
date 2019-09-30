/*
 * FILE: C.cpp
 *
 * @author: Piyush Kanti Das <piyush123kantidas[at]gmail[dot]com>
 *
 * LINK:
 *
 * DATE CREATED: 22.08.2019 20:28:13 +06
 *
 * DESCRIPTION:
 *
 * DEVELOPMENT HISTORY:
 * Date         Version     Description
 * --------------------------------------------------------------
 * 22-08-2019   1.0         File Created
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
#define INF             0x7ffffffffffff
#define MOD             1000000007
#define EPS             1e-7
#define MAX             100005

int Set(int N, int pos) {
    return N = N | (1 << pos);
}
int Reset(int N, int pos) {
    return N = N & ~(1 << pos);
}
bool Check(int N, int pos) {
    return (bool)(N & (1 << pos));
}


ll BM( ll a, ll b, ll m ) {
    if ( b == 0 ) return 1 ;
    ll x = BM(a, b / 2, m);
    x = (( x % m) * (x % m)) % m;

    if ( b % 2 ) x = (( x % m) * (a % m)) % m ;
    return x ;
}

//Auto-format --> ctrl+shift+a
/********************* Code starts here ************************/
ll  num0[MAX * 2], num1[2 * MAX];
int main() {
    __FastIO;   //Be aware to use it!

    int test;

    cin >> test;

    while (test--) {
        ll n, a, b, calc, ans;

        cin >> n >> a >> b;
        string s;
        cin >> s;
        s.pb('#');

        calc = (4LL * a) + 2LL * b + (n - 2LL) * a + ((n - 1LL) * 2LL * b);
        ans = calc;
          //debug1(calc);

        
           int cnt1 = 0, cnt0 = 0;
        for (ll i = n - 1; i >= 0; i--) {
            if (s[i] == '0') {
                cnt0++;
                num0[i] = cnt0;
                num1[i] = cnt1;
            } else {
                
                num0[i] = cnt0;
                num1[i] = cnt1;
                cnt1++;
                cnt0 = 0;
            }
        }


        calc = b;

        for(ll i = 0; i < n; i++) {
			//debug2(i, num0[i]);
            if (s[i] == '0') {
				if(i == n - 1){
					calc += (a + b);
					continue;
				}
                //calc += b;
                if (s[i + 1] == '1') {
                    calc += (b * 2);
                    calc += (a * 2);
                    continue;
                } else {
					ll option1 = INF, option2 = INF;
					
					
                    option1 = a;
                    option1 += (num0[i]*a + num0[i]*(2LL * b));
                  //  i += (num0[i] - 1);
                    if(i + (num0[i] - 1) == n - 1){
						option1 -= b;
						option1 += a;
					}
				
				option2 = num0[i] * (a + b);
				if(num1[i] > 0){
					option2 += (a + b);
				}
				
				calc += min(option1, option2);
				i += (num0[i] - 1);
				
                }
            } else {
                if (s[i + 1] == '0') {
                    //if((cnt0[i] - 1LL )* )
                    if (i + 1 == n - 1) {
                        calc += (2 * b);
                        calc += (2 * a);
                        continue;
                    }
						ll option1 = INF, option2 = INF;
						
                        
                             option1 =  2LL*b*(num0[i] + 1) + a * (num0[i] + 1);
                            //calc += (2LL * a) + a;
                            //i++;
                            if(i + num0[i] == n - 1){
								option1 -= b;
								option1 += a;
							}
                        
                        if(num0[i] >= 2){
                        option2 = 2LL*(a + b);
                        option2 += ((a + b)*num0[i]);
                        if(num1[i] > 0){
							option2 += (a + b);
						} 
                        }
                        
                        i += num0[i];
                        calc += min(option1, option2);
                    
                } else {
                    calc += (a + b*2LL);
                }
            }
            //debug2(i, calc);
        }
		//debug1(calc);
        ans = min(ans, calc);

        cout << ans << endl;
    }
    return 0;
}
