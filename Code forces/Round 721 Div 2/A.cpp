#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int test;

    cin >> test;

    while(test--){
        long long n;
        cin >> n;

        long long lg = log2(n);

        long long ans = (1 << lg) - 1;

        cout << ans << endl;

    }
}
