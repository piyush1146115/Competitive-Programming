#include<bits/stdc++.h>
using namespace std;
int main()
{
    int i, j, mx, n , ans;
    map <vector<int> , int> m;
    vector <int> v;

    while(scanf("%d", &n) == 1){
        if(n == 0)
            break;
            mx =  -1;
            ans = 0;
        while(n--){
            for(i = 0; i < 5; i++){
                scanf("%d", &j);
                v.push_back(j);
            }
            sort(v.begin(), v.end());
            m[v]++;
            if(m[v] > mx){
                mx = m[v];
            }
            v.clear();
        }
        map<vector <int>, int> :: iterator it;

        for(it = m.begin(); it != m.end(); it++){
            if((*it).second == mx){
                ans += (*it).second;
            }
        }
        cout << ans << endl;
        m.clear();
    }
    return 0;
}
