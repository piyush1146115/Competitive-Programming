#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int len(ll n)
{
    int ret = 0;

    while(n != 0){
        ret++;
        n /= 10;
    }

    return ret;
}

int main()
{
    ios_base::sync_with_stdio(false);
    int n;

    cin >> n;

    while(n--){
        ll x, y, z;
        ll a, b, c;

        x = y= z = 1;

        cin >> a >> b >> c;

        while(len(z) < c){
            z *= 2;
        }

        x = y = z;

        while(len(x) < a){
            x *= 3;
        }

        while(len(y) < b)
            y *= 5;


        cout << x << " " << y << endl;

    }

}
