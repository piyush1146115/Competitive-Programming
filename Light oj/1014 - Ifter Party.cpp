/*
 * FILE: 1014 - Ifter Party.cpp
 *
 * @author: Piyush Kanti Das <piyush123kantidas[at]gmail[dot]com>
 *
 * LINK:
 *
 * DATE CREATED: 30.11.2017 18:52:36 +06
 *
 * DESCRIPTION:
 *
 * DEVELOPMENT HISTORY:
 * Date         Version     Description
 * --------------------------------------------------------------
 * 30-11-2017   1.0         File Created
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
#define MOD             1000000007
#define EPS             1e-7
#define MAX             100005
 
/********************* Code starts here ************************/
 
int main() {
    //__FastIO;   //Be aware to use it!
   
    int test;
   
    scanf("%d", &test);
    vi div;
    forr(tc, 1, test){
        int p, l;
       
        scanf("%d %d", &p, &l);
       
       
        int used = p - l;
       int sqrtn = (int)sqrt(used);
       
       for(int i = 1; i <= sqrtn; i++){
		   if(used % i == 0){
			   div.pb(i);
			   if(i * i == used)
			   continue;
			   div.pb(used/i);
		   }
	   }
        sort(all(div));
        
       int sz = (int)div.size();
       
        
        int flag = 1;
            printf("Case %d:",tc);
           
            for(int i = 0; i < sz; i++){
				if(div[i] > l){
                printf(" %d",div[i]);
                flag = 0;
			}
            }
           
            
            if(flag)
            printf(" impossible");
            
            printf("\n");
            div.clear();
           
        }
    
    return 0;
}
