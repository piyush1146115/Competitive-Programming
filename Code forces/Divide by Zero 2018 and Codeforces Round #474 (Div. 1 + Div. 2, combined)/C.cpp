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
#define MOD             100000000007
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

ll ans[MAX];
int main() {
    __FastIO;   //Be aware to use it
    ll ind = 0;
    ll n, d;
    cin >> n >> d;
    ll po;
    for(ll i = 1; i <= n; i++){
        ll val = BM(2, i, MOD) - 1;
        if(val <= n){
            po = i;
        }
        else{
            break;
        }
    }
    n -= (BM(2, po, MOD) - 1);
    while(po--){
        ans[ind++] = 1;
    }

    if(n == 0){
        cout << ind << endl;
        rep(i, ind){
        cout << ans[i] << " ";
        }
        cout << endl;
        return 0;
    }
    if(n == 1){
        cout << ind + 1 << endl;
        rep(i, ind){
        cout << ans[i] << " ";
        }

        cout << 1000000000000000 << endl;
        cout << endl;
        return 0;
    }

    for(ll i = 1; i <= n; i++){
        ll val = BM(2, i, MOD) - 1;
        if(val <= n){
            po = i;
        }
        else{
            break;
        }
    }
    n -= (BM(2, po, MOD) - 1);
    while(po--){
        ans[ind++] = 1 + (d * 3);
    }

    if(n == 0){
        cout << ind << endl;
        rep(i, ind){
        cout << ans[i] << " ";
        }
        cout << endl;
        return 0;
    }
    if(n == 1){
        cout << ind + 1 << endl;
        rep(i, ind){
        cout << ans[i] << " ";
        }

        cout << 1000000000000000 << endl;
        cout << endl;
        return 0;
    }

    for(ll i = 1; i <= n; i++){
        ll val = BM(2, i, MOD) - 1;
        if(val <= n){
            po = i;
        }
        else{
            break;
        }
    }
    n -= (BM(2, po, MOD) - 1);
    while(po--){
        ans[ind++] = 1 + (d * 5 );
    }

    if(n == 0){
        cout << ind << endl;
        rep(i, ind){
        cout << ans[i] << " ";
        }
        cout << endl;
        return 0;
    }
    if(n == 1){
        cout << ind + 1 << endl;
        rep(i, ind){
        cout << ans[i] << " ";
        }

        cout << 1000000000000000 << endl;
        cout << endl;
        return 0;
    }

    for(ll i = 1; i <= n; i++){
        ll val = BM(2, i, MOD) - 1;
        if(val <= n){
            po = i;
        }
        else{
            break;
        }
    }
    n -= (BM(2, po, MOD) - 1);
    while(po--){
        ans[ind++] = 1 + (d * 7);
    }

    if(n == 0){
        cout << ind << endl;
        rep(i, ind){
        cout << ans[i] << " ";
        }
        cout << endl;
        return 0;
    }
    if(n == 1){
        cout << ind + 1 << endl;
        rep(i, ind){
        cout << ans[i] << " ";
        }

        cout << 1000000000000000 << endl;
        cout << endl;
        return 0;
    }

    for(ll i = 1; i <= n; i++){
        ll val = BM(2, i, MOD) - 1;
        if(val <= n){
            po = i;
        }
        else{
            break;
        }
    }
    n -= (BM(2, po, MOD) - 1);
    while(po--){
        ans[ind++] = 1 + (d * 9);
    }

    if(n == 0){
        cout << ind << endl;
        rep(i, ind){
        cout << ans[i] << " ";
        }
        cout << endl;
        return 0;
    }
    if(n == 1){
        cout << ind + 1 << endl;
        rep(i, ind){
        cout << ans[i] << " ";
        }

        cout << 1000000000000000 << endl;
        cout << endl;
        return 0;
    }

    for(ll i = 1; i <= n; i++){
        ll val = BM(2, i, MOD) - 1;
        if(val <= n){
            po = i;
        }
        else{
            break;
        }
    }
    n -= (BM(2, po, MOD) - 1);
    while(po--){
        ans[ind++] = 1 + (d * 11);
    }

    if(n == 0){
        cout << ind << endl;
        rep(i, ind){
        cout << ans[i] << " ";
        }
        cout << endl;
        return 0;
    }
    if(n == 1){
        cout << ind + 1 << endl;
        rep(i, ind){
        cout << ans[i] << " ";
        }

        cout << 1000000000000000 << endl;
        cout << endl;
        return 0;
    }

    for(ll i = 1; i <= n; i++){
        ll val = BM(2, i, MOD) - 1;
        if(val <= n){
            po = i;
        }
        else{
            break;
        }
    }
    n -= (BM(2, po, MOD) - 1);
    while(po--){
        ans[ind++] = 1 + (d * 13);
    }

    if(n == 0){
        cout << ind << endl;
        rep(i, ind){
        cout << ans[i] << " ";
        }
        cout << endl;
        return 0;
    }
    if(n == 1){
        cout << ind + 1 << endl;
        rep(i, ind){
        cout << ans[i] << " ";
        }

        cout << 1000000000000000 << endl;
        cout << endl;
        return 0;
    }

    for(ll i = 1; i <= n; i++){
        ll val = BM(2, i, MOD) - 1;
        if(val <= n){
            po = i;
        }
        else{
            break;
        }
    }
    n -= (BM(2, po, MOD) - 1);
    while(po--){
        ans[ind++] = 1 + (d * 15);
    }

    if(n == 0){
        cout << ind << endl;
        rep(i, ind){
        cout << ans[i] << " ";
        }
        cout << endl;
        return 0;
    }
    if(n == 1){
        cout << ind + 1 << endl;
        rep(i, ind){
        cout << ans[i] << " ";
        }

        cout << 1000000000000000 << endl;
        cout << endl;
        return 0;
    }

    for(ll i = 1; i <= n; i++){
        ll val = BM(2, i, MOD) - 1;
        if(val <= n){
            po = i;
        }
        else{
            break;
        }
    }
    n -= (BM(2, po, MOD) - 1);
    while(po--){
        ans[ind++] = 1 + (d * 17);
    }

    if(n == 0){
        cout << ind << endl;
        rep(i, ind){
        cout << ans[i] << " ";
        }
        cout << endl;
        return 0;
    }
    if(n == 1){
        cout << ind + 1 << endl;
        rep(i, ind){
        cout << ans[i] << " ";
        }

        cout << 1000000000000000 << endl;
        cout << endl;
        return 0;
    }

    for(ll i = 1; i <= n; i++){
        ll val = BM(2, i, MOD) - 1;
        if(val <= n){
            po = i;
        }
        else{
            break;
        }
    }
    n -= (BM(2, po, MOD) - 1);
    while(po--){
        ans[ind++] = 1 + (d * 19);
    }

    if(n == 0){
        cout << ind << endl;
        rep(i, ind){
        cout << ans[i] << " ";
        }
        cout << endl;
        return 0;
    }
    if(n == 1){
        cout << ind + 1 << endl;
        rep(i, ind){
        cout << ans[i] << " ";
        }

        cout << 1000000000000000 << endl;
        cout << endl;
        return 0;
    }

    for(ll i = 1; i <= n; i++){
        ll val = BM(2, i, MOD) - 1;
        if(val <= n){
            po = i;
        }
        else{
            break;
        }
    }
    n -= (BM(2, po, MOD) - 1);
    while(po--){
        ans[ind++] = 1 + (d * 21);
    }

    if(n == 0){
        cout << ind << endl;
        rep(i, ind){
        cout << ans[i] << " ";
        }
        cout << endl;
        return 0;
    }
    if(n == 1){
        cout << ind + 1 << endl;
        rep(i, ind){
        cout << ans[i] << " ";
        }

        cout << 1000000000000000 << endl;
        cout << endl;
        return 0;
    }

    for(ll i = 1; i <= n; i++){
        ll val = BM(2, i, MOD) - 1;
        if(val <= n){
            po = i;
        }
        else{
            break;
        }
    }
    n -= (BM(2, po, MOD) - 1);
    while(po--){
        ans[ind++] = 1 + (d * 23);
    }

    if(n == 0){
        cout << ind << endl;
        rep(i, ind){
        cout << ans[i] << " ";
        }
        cout << endl;
        return 0;
    }
    if(n == 1){
        cout << ind + 1 << endl;
        rep(i, ind){
        cout << ans[i] << " ";
        }

        cout << 1000000000000000 << endl;
        cout << endl;
        return 0;
    }


    for(ll i = 1; i <= n; i++){
        ll val = BM(2, i, MOD) - 1;
        if(val <= n){
            po = i;
        }
        else{
            break;
        }
    }
    n -= (BM(2, po, MOD) - 1);
    while(po--){
        ans[ind++] = 1 + (d * 25);
    }

    if(n == 0){
        cout << ind << endl;
        rep(i, ind){
        cout << ans[i] << " ";
        }
        cout << endl;
        return 0;
    }
    if(n == 1){
        cout << ind + 1 << endl;
        rep(i, ind){
        cout << ans[i] << " ";
        }

        cout << 1000000000000000 << endl;
        cout << endl;
        return 0;
    }


    for(ll i = 1; i <= n; i++){
        ll val = BM(2, i, MOD) - 1;
        if(val <= n){
            po = i;
        }
        else{
            break;
        }
    }
    n -= (BM(2, po, MOD) - 1);
    while(po--){
        ans[ind++] = 1 + (d * 27);
    }

    if(n == 0){
        cout << ind << endl;
        rep(i, ind){
        cout << ans[i] << " ";
        }
        cout << endl;
        return 0;
    }
    if(n == 1){
        cout << ind + 1 << endl;
        rep(i, ind){
        cout << ans[i] << " ";
        }

        cout << 1000000000000000 << endl;
        cout << endl;
        return 0;
    }


    for(ll i = 1; i <= n; i++){
        ll val = BM(2, i, MOD) - 1;
        if(val <= n){
            po = i;
        }
        else{
            break;
        }
    }
    n -= (BM(2, po, MOD) - 1);
    while(po--){
        ans[ind++] = 1 + (d * 29);
    }

    if(n == 0){
        cout << ind << endl;
        rep(i, ind){
        cout << ans[i] << " ";
        }
        cout << endl;
        return 0;
    }
    if(n == 1){
        cout << ind + 1 << endl;
        rep(i, ind){
        cout << ans[i] << " ";
        }

        cout << 1000000000000000 << endl;
        cout << endl;
        return 0;
    }


    for(ll i = 1; i <= n; i++){
        ll val = BM(2, i, MOD) - 1;
        if(val <= n){
            po = i;
        }
        else{
            break;
        }
    }
    n -= (BM(2, po, MOD) - 1);
    while(po--){
        ans[ind++] = 1 + (d * 31);
    }

    if(n == 0){
        cout << ind << endl;
        rep(i, ind){
        cout << ans[i] << " ";
        }
        cout << endl;
        return 0;
    }
    if(n == 1){
        cout << ind + 1 << endl;
        rep(i, ind){
        cout << ans[i] << " ";
        }

        cout << 1000000000000000 << endl;
        cout << endl;
        return 0;
    }

    for(ll i = 1; i <= n; i++){
        ll val = BM(2, i, MOD) - 1;
        if(val <= n){
            po = i;
        }
        else{
            break;
        }
    }
    n -= (BM(2, po, MOD) - 1);
    while(po--){
        ans[ind++] = 1 + (d * 33);
    }

    if(n == 0){
        cout << ind << endl;
        rep(i, ind){
        cout << ans[i] << " ";
        }
        cout << endl;
        return 0;
    }
    if(n == 1){
        cout << ind + 1 << endl;
        rep(i, ind){
        cout << ans[i] << " ";
        }

        cout << 1000000000000000 << endl;
        cout << endl;
        return 0;
    }

    for(ll i = 1; i <= n; i++){
        ll val = BM(2, i, MOD) - 1;
        if(val <= n){
            po = i;
        }
        else{
            break;
        }
    }
    n -= (BM(2, po, MOD) - 1);
    while(po--){
        ans[ind++] = 1 + (d * 35);
    }

    if(n == 0){
        cout << ind << endl;
        rep(i, ind){
        cout << ans[i] << " ";
        }
        cout << endl;
        return 0;
    }
    if(n == 1){
        cout << ind + 1 << endl;
        rep(i, ind){
        cout << ans[i] << " ";
        }

        cout << 1000000000000000 << endl;
        cout << endl;
        return 0;
    }

    for(ll i = 1; i <= n; i++){
        ll val = BM(2, i, MOD) - 1;
        if(val <= n){
            po = i;
        }
        else{
            break;
        }
    }
    n -= (BM(2, po, MOD) - 1);
    while(po--){
        ans[ind++] = 1 + (d * 35);
    }

    if(n == 0){
        cout << ind << endl;
        rep(i, ind){
        cout << ans[i] << " ";
        }
        cout << endl;
        return 0;
    }
    if(n == 1){
        cout << ind + 1 << endl;
        rep(i, ind){
        cout << ans[i] << " ";
        }

        cout << 1000000000000000 << endl;
        cout << endl;
        return 0;
    }


    for(ll i = 1; i <= n; i++){
        ll val = BM(2, i, MOD) - 1;
        if(val <= n){
            po = i;
        }
        else{
            break;
        }
    }
    n -= (BM(2, po, MOD) - 1);
    while(po--){
        ans[ind++] = 1 + (d * 37);
    }

    if(n == 0){
        cout << ind << endl;
        rep(i, ind){
        cout << ans[i] << " ";
        }
        cout << endl;
        return 0;
    }
    if(n == 1){
        cout << ind + 1 << endl;
        rep(i, ind){
        cout << ans[i] << " ";
        }

        cout << 1000000000000000 << endl;
        cout << endl;
        return 0;
    }


    for(ll i = 1; i <= n; i++){
        ll val = BM(2, i, MOD) - 1;
        if(val <= n){
            po = i;
        }
        else{
            break;
        }
    }
    n -= (BM(2, po, MOD) - 1);
    while(po--){
        ans[ind++] = 1 + (d * 39);
    }

    if(n == 0){
        cout << ind << endl;
        rep(i, ind){
        cout << ans[i] << " ";
        }
        cout << endl;
        return 0;
    }
    if(n == 1){
        cout << ind + 1 << endl;
        rep(i, ind){
        cout << ans[i] << " ";
        }

        cout << 1000000000000000 << endl;
        cout << endl;
        return 0;
    }


    for(ll i = 1; i <= n; i++){
        ll val = BM(2, i, MOD) - 1;
        if(val <= n){
            po = i;
        }
        else{
            break;
        }
    }
    n -= (BM(2, po, MOD) - 1);
    while(po--){
        ans[ind++] = 1 + (d * 41);
    }

    if(n == 0){
        cout << ind << endl;
        rep(i, ind){
        cout << ans[i] << " ";
        }
        cout << endl;
        return 0;
    }
    if(n == 1){
        cout << ind + 1 << endl;
        rep(i, ind){
        cout << ans[i] << " ";
        }

        cout << 1000000000000000 << endl;
        cout << endl;
        return 0;
    }

    for(ll i = 1; i <= n; i++){
        ll val = BM(2, i, MOD) - 1;
        if(val <= n){
            po = i;
        }
        else{
            break;
        }
    }
    n -= (BM(2, po, MOD) - 1);
    while(po--){
        ans[ind++] = 1 + (d * 43);
    }

    if(n == 0){
        cout << ind << endl;
        rep(i, ind){
        cout << ans[i] << " ";
        }
        cout << endl;
        return 0;
    }
    if(n == 1){
        cout << ind + 1 << endl;
        rep(i, ind){
        cout << ans[i] << " ";
        }

        cout << 1000000000000000 << endl;
        cout << endl;
        return 0;
    }


    for(ll i = 1; i <= n; i++){
        ll val = BM(2, i, MOD) - 1;
        if(val <= n){
            po = i;
        }
        else{
            break;
        }
    }
    n -= (BM(2, po, MOD) - 1);
    while(po--){
        ans[ind++] = 1 + (d * 45);
    }

    if(n == 0){
        cout << ind << endl;
        rep(i, ind){
        cout << ans[i] << " ";
        }
        cout << endl;
        return 0;
    }
    if(n == 1){
        cout << ind + 1 << endl;
        rep(i, ind){
        cout << ans[i] << " ";
        }

        cout << 1000000000000000 << endl;
        cout << endl;
        return 0;
    }

    for(ll i = 1; i <= n; i++){
        ll val = BM(2, i, MOD) - 1;
        if(val <= n){
            po = i;
        }
        else{
            break;
        }
    }
    n -= (BM(2, po, MOD) - 1);
    while(po--){
        ans[ind++] = 1 + (d * 47);
    }

    if(n == 0){
        cout << ind << endl;
        rep(i, ind){
        cout << ans[i] << " ";
        }
        cout << endl;
        return 0;
    }
    if(n == 1){
        cout << ind + 1 << endl;
        rep(i, ind){
        cout << ans[i] << " ";
        }

        cout << 1000000000000000 << endl;
        cout << endl;
        return 0;
    }

    for(ll i = 1; i <= n; i++){
        ll val = BM(2, i, MOD) - 1;
        if(val <= n){
            po = i;
        }
        else{
            break;
        }
    }
    n -= (BM(2, po, MOD) - 1);
    while(po--){
        ans[ind++] = 1 + (d * 49);
    }

    if(n == 0){
        cout << ind << endl;
        rep(i, ind){
        cout << ans[i] << " ";
        }
        cout << endl;
        return 0;
    }
    if(n == 1){
        cout << ind + 1 << endl;
        rep(i, ind){
        cout << ans[i] << " ";
        }

        cout << 1000000000000000 << endl;
        cout << endl;
        return 0;
    }
    cout << -1 << endl;
    return 0;
}
