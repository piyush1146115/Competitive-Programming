#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
    int test;
    cin >> test;

    while(test--){
        ll n, k;
        ll ans;

        cin >> n >> k;

        if(n % 2 == 0){
            if(k % n == 0){
                ans = n;
            }
            else
                ans = k % n;
        }
        else{
            if(k <= n){
                if(k <= (n/2))
                    ans = k;
                else if(k == n){
                    ans = 2;
                }
                else{
                    ans = k + 1;
                }
            }
            else{
                ans = ((k/(n/2)) + (k%n))%n;
                if(ans == 0)
                    ans = n;

                if(k % (n/2) == 0)
                    ans--;
                
                if(ans == 0)
                    ans = n;
            }
        }
        cout << ans << endl;
    }

}