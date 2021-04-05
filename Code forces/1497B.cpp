#include<bits/stdc++.h>
using namespace std;
 
int main()
{
    ios_base::sync_with_stdio(false);
    int test;
    cin >> test;
 
    while(test--)
    {
        int n, m;
        cin >> n >> m;
        map<int, int> mp;
 
        for(int i = 0; i < n; i++){
            int k;
            cin >> k;
            mp[k%m]++;
        }
 
        int ans = 0;
 
        if(mp.find(0) != mp.end())
            ans++;
 
        // cout << ans << endl;
 
        for(int i = 1; i < m; i++){
            if(mp[i] > 0){
 
                int p = m - i;
                if(mp[p] > 0){
                    ans++;
                    int mn = min(mp[p], mp[i]);
                    mp[p] -= (mn + 1);
                    mp[i] -= (mn + 1);
                    if(mp[p] > 0){
                        ans += (mp[p]);
                        mp[p] = 0;
                    }
 
                    // cout << i << " " << mn << " " << mp[i]  << " " << mp[p] << endl;
                }
                if(mp[i] > 0)
                    ans += (mp[i]);
 
                    
            }
            // cout << i << " " << ans << endl; 
        }
 
        cout << ans << endl;
        /* code */
    }
    
}