#include<bits/stdc++.h>
using namespace std;
#define ll long long
vector<ll> odd, even;
int main()
{

    ll n, temp;
    cin >> n;


    for(int i = 0; i < n; i++){
        cin >> temp;
        if(temp %2 == 0){
            even.push_back(temp);
        }else{
            odd.push_back(temp);
        }
    }

    if(abs((int)even.size() - (int)odd.size()) <= 1){
        cout << 0 << endl;
    }else{
        ll sum = 0LL;
        if(odd.size() > even.size()){
        sort(odd.begin(),odd.end());
            for(int i = 0; i < ((int)odd.size() - even.size() - 1); i++){
                sum += odd[i];
            }
        }else{
        sort(even.begin(),even.end());
            for(int i = 0; i < ((int)even.size() - odd.size() - 1); i++){
                sum += even[i];
            }

        }
        cout << sum << endl;
    }
}
