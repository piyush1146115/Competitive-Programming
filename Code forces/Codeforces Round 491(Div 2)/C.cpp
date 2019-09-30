#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n;
bool fun(ll in)
{
    ll temp = n;
    ll sum = 0;
    while(temp > 0){
        sum += min(in, temp);
        temp -= in;
        temp -= (temp/10);
    }
    if(sum * 2 >= n){
        return true;
    }
    return false;
}

int main()
{

    cin >> n;

    ll mid, lo = 1, hi = n;
    ll ans;
    while(lo <= hi){
        mid = (lo + hi)/2;
        if(fun(mid)){
            hi = mid - 1;
            ans = mid;
        }
        else{
            lo = mid + 1;
        }
    }

    cout << ans << endl;
}
