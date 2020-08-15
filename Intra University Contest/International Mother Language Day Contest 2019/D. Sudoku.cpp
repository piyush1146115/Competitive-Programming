/*
 * FILE: D. Sudoku.cpp
 *
 * @author: Piyush Kanti Das <piyush123kantidas[at]gmail[dot]com>
 *
 * LINK:
 *
 * DATE CREATED: 21.02.2019 11:13:29 +06
 *
 * DESCRIPTION:
 *
 * DEVELOPMENT HISTORY:
 * Date         Version     Description
 * --------------------------------------------------------------
 * 21-02-2019	1.0         File Created
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

//Auto-format --> ctrl+shift+a
/********************* Code starts here ************************/

string s[12];

int flag[12];

bool checkCol(){
	rep(i, 9){
		clr(flag);
		rep(j, 9){
			flag[(int)(s[i][j] - '0')]++;
		}
		for(int c = 1; c <= 9; c++){
				if(flag[c] == 0){
					return false;
				}
			}
	}
	return true;
}

bool checkRow(){
		rep(j, 9){
			clr(flag);
			rep(i, 9){
				flag[(int)(s[i][j] - '0')]++;
			}
			for(int c = 1; c <= 9; c++){
				if(flag[c] == 0){
					return false;
				}
			}
		}
		
		return true;
}
	


bool checkMat(){
	
	for(int i = 0; i < 9; i+= 3){
		for(int j = 0; j < 9; j+= 3){
			clr(flag);
			for(int k = 0; k < 3;k++){
				for(int l = 0; l < 3; l++){
					flag[(int)(s[i +k][j+l] - '0')]++;
				}
			}
			
			for(int c = 1; c <= 9; c++){
				if(flag[c] == 0){
					return false;
				}
			}
		}
	}
	
	return true;
}
int main() {
    __FastIO;   //Be aware to use it!
    
    int test;
    cin >> test;
    
    while(test--){
		
		rep(i, 9){
			cin >> s[i];
		}
		
		if(checkRow()&&checkCol()&&checkMat()){
			cout << "Valid\n";
		}else{
			cout << "Invalid\n";
		}
	}
    return 0;
}
