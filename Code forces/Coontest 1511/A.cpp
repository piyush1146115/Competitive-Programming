#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    int test;
    cin >> test;

    while(test--){
        int n;
        cin >> n;

        int ans = 0;
        for(int i = 0; i < n; i++){
            int k;
            cin >> k;
            if(k != 2)
                ans++;
        }

        cout << ans << endl;
    }

}
