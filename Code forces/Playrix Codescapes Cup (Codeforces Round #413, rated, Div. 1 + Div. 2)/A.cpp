#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    int n, t, k, d;

    cin >> n >> t >> k >> d;

    int m, t1;
    int flag = 0;

    for(int i = 1;; i++){
        m = i * k;
        if(m >= n)
            break;
        t1 = i * t;
        if(t1 > d)
        {
            flag = 1;
            break;
        }
    }

    if(flag)
        cout << "YES" << endl;
    else
        cout << "NO\n";
}
