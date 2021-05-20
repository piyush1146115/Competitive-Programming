#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int test, n;
    cin >> test;

    vector<long long> v(100000 + 5);
    while(test--){
        cin >> n;
        map<long long, long long int> mp;

        long long ans = 0;

        for(int i = 1; i <= n; i++){
            cin >> v[i];

            ans += (mp[v[i]] * (n - i + 1));
            mp[v[i]] += i;
        }


//
//        for(int i = 0; i < n; i++){
//            if(mp[v[i]] > 1){
//                long long cnt = mp[v[i]];
//
//                long long cal = (cnt*(cnt - 1))/2;
//                long long dif = (i + (n - lst[v[i]]));
//                //dif = max(dif, (dif*(dif - 1))/2);
//            //    cout << i << " " << dif << " " << cal << endl;
//
//                ans += (cal + (cal * dif));
//                if(dif > 3)
//                    mp[v[i]] = 0;
//
//                mp[v[i]]--;
//            }
//        }

        cout << ans << endl;
    }
}
