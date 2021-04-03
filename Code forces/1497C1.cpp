#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ll test, n, k;
    cin >> test;

    while(test--){
        cin >> n >> k;

        if(n % 2 == 0){
            if((n/2) % 2 == 0){
                cout << n/2  << " " << n/4 <<  " " << n/4 << endl ;
            }
            else{
                cout << 2 << " ";
                n -= 2;
                cout << n/2 << " " << n/2 << endl;
            }
        }
        else{
            cout << 1 << " " << (n-1)/2 << " " << (n-1)/2 << endl;
        }
    }

    
}