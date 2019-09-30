#include<bits/stdc++.h>
using namespace std;
int main()
{
    int test;
    cin >> test;

    int n, mx = 0;
    map<string, int>mp, mark;
    string ans, s;
    vector< pair<string, int> > v;
    while(test--){
        cin >> s >> n;
        mp[s] += n;
        v.push_back({s, n});
    }

    for(int i = 0; i < (int)v.size(); i++){
        mx = max(mx, mp[v[i].first]);
    }
    
    int cnt = 0;
    
    for(int i = 0; i < (int)v.size(); i++){
        if(mp[v[i].first] == mx){
            cnt++;
            mark[v[i].first] = 2;
            ans = v[i].first;
        }
        
       // mx = max(mx, mp[s]);
    }
    
    if(cnt == 1){
		cout << ans << endl;
		exit(0);
	}
    
    
    mp.clear();
//	mx = 0;
	
    for(int i = 0 ; i < (int)v.size(); i++){
        if(mark[v[i].first] == 2){
            mp[v[i].first] += v[i].second;
           // cout <<v[i].first << " " << v[i].second << " " <<  mp[v[i].first] << endl;
            if(mp[v[i].first] == mx){
                mx = mp[v[i].first];
                ans = v[i].first;
                break;
            }
        }
    }


    cout << ans << endl;

}
