#include<bits/stdc++.h>
using namespace std;
int main()
{
    //freopen("input.txt", "r", stdin);
    map <string, int> mp;
    string s;
    long long sum, i, j, k, val, m, n;

    while(cin >> n >> m){

    for(i = 0; i < n; i++){
        cin >> s >> val;
        mp[s] = val;
    }

    while(m--){
             sum = 0;
        while(cin >> s){
            if(s == "."){
                break;
            }
            sum += mp[s];
        }
        cout << sum << endl;
    }
    mp.clear();
    }
    return 0;
}
