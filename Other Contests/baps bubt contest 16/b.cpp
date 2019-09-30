#include<bits/stdc++.h>
using namespace std;
int main()
{
    map<string, int> mp;
    string s, ans;
    int a, c = 0, mx, test, i, j, k;

    scanf("%d", &test);

    while(test--){
        scanf("%d", &k);
        mx = -1;
        for(i = 0; i < k; i++){
            cin >> s;
            mp[s]++;
            if(mp[s] > mx){
                mx = mp[s];
                ans = s;
            }
        }
        printf("Case %d: ",++c);
        cout << ans << endl;

        mp.clear();
    }
    return 0;
}
