/*
 * FILE: C.cpp
 *
 * @author: Piyush Kanti Das <piyush123kantidas[at]gmail[dot]com>
 *
 * LINK:
 *
 * DATE CREATED: 01.10.2019 20:33:47 +06
 *
 * DESCRIPTION:
 *
 * DEVELOPMENT HISTORY:
 * Date         Version     Description
 * --------------------------------------------------------------
 * 01-10-2019	1.0         File Created
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
typedef vector< vi >        vvi;
typedef vector<long long>   vll;


#define __FastIO        ios_base::sync_with_stdio(false); cin.tie(0)

#define forr(i, a, b)   for (__typeof (a) i=a; i<=b; i++)
#define rof(i, b, a)    for (__typeof (a) i=b; i>=a; i--)
#define rep(i, n)       for (__typeof (n) i=0; i<n; i++)
#define tr(i,c) 		for(typeof((c)).begin() i = (c).begin(); i != (c).end(); i++)
#define all(ar)         ar.begin(), ar.end()

#define present(c,x) ((c).find(x) != (c).end()) // for map/set
#define cpresent(c,x) (find(all(c),x) != (c).end()) // for vectors


#define fill(ar)   		memset(ar, -1, sizeof(ar))
#define clr(a)          memset(a, 0, sizeof(a))

#define nl              cout << '\n';
#define sp              cout << ' ';
#define ckk             cout << "##########\n"

#define pb              push_back
#define MP 				make_pair
#define sz(a)           int((a).size())


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

int grid[5][2 * MAX];


void reset(int n)
{
	forr(i, 0, n + 5){
		grid[1][i] = grid[2][i] =  0;
	}
}


int main() {
    __FastIO;   //Be aware to use it!
    
    int n, q;
    cin >> q;
    
    while(q--){
		string s[5];
		cin >> n;
		
		cin >> s[1] >> s[2];
		
		
		reset(n);
		
		grid[1][1] = 3;
		
		int col = 1, row = 1, flag = 1;
		
		while(col <= n){
			if(grid[row][col] <= 2){
				if(s[row][col - 1] <= '2'){
					flag = 0;
					break;
				}else{
					col++;
					grid[row][col] = 3;
				}
				
			}
			else if(grid[row][col] == 3){
				if(s[row][col - 1] <= '2'){
					col++;
					grid[row][col] = 3;
					
				}
				else{
					if(row == 1){
						row++;
						grid[row][col] = 1;
					}
					else if(row == 2){
						row--;
						grid[row][col] = 2;
					}
				}
			}
		}
		
		if(flag == 0){
			cout << "NO" << endl;
			continue;
		}
		
		if(grid[2][n] == 3 && s[2][n - 1] <= '2'){
			cout << "YES" << endl;
			continue;
		}
				
		if(grid[2][n] == 1 && s[2][n - 1] > '2'){
			cout << "YES" << endl;
			continue;
		}
		
		cout << "NO" << endl;
		
		
	}
    return 0;
}
