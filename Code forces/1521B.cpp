#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int test;

    cin >> test;

    while(test--){
        int n;
        cin >> n;

        vector<long long> v(n + 2);

        long long pos, x = 2e10;

        for(int i = 0; i < n; i++){
            cin >> v[i];

            if(v[i] < x){
                x = v[i];
                pos = i;
            }
        }

        cout << n - 1 << endl;

        for(int i = 0; i < n; i++){
            if(i != pos){
                cout << pos + 1 << " " << i + 1 << " " << x << " " << x + abs(pos - i) << endl;
            }
        }
    }
    return 0;
}
