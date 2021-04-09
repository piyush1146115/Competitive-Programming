#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(false);

    ll test;
    cin >> test;

    while(test--){
        ll n, u, v;

        cin >> n >> u >> v;
        vector<int> vec(n + 5);

        for(int i = 0; i < n; i++){
            cin >> vec[i];
        }

        int flag = 1;

        for(int i = 1; i < n; i++){
            if(vec[i] == vec[i - 1])
                continue;

            if(abs(vec[i] - vec[i - 1]) == 1)
                flag = 2;
            else{
                flag = 0;
                break;
            }
        }

        if(flag == 0){
            cout << 0 << endl;
        }
        else if(flag == 2){
            cout << min(u,v) << endl;
        }
        else{
                cout << min(u+v, 2*v) << endl;

        }
    }
}
