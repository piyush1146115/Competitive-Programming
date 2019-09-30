#include<bits/stdc++.h>
using namespace std;
int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int test, i, j, k, n, m;

    map<string, string> ms;
    map<string, int> si;
    map<int, string> is;
    set<string> s;

    string s1, s2;

    scanf("%d", &test);

    while(test--){
        scanf("%d\n", &n);

        for(i = 0; i < n; i++){
            getline(cin, s1);
            getline(cin, s2);
            ms[s1] = s2;
            s.insert(s1);
        }

        scanf("%d\n", &n);
        int mx = 0;

        for(i = 0; i < n; i++){
            getline(cin, s1);

            if(s.count(s1) != 0){
            si[s1]++;
            mx = max(mx, si[s1]);
            is[si[s1]] = s1;
            }
        }
        int co = 0;

        map<string, int> :: iterator it;
        string ans;
        for(it = si.begin(); it != si.end(); it++){
            if((*it).second == mx){
                co++;
                ans = ms[is[mx]];
            }
        }
        if(co == 1){
            cout << ans << endl;
        }
        else
            cout << "tie\n";

        ms.clear();
        si.clear();
        is.clear();
        s.clear();

        if(test)
            printf("\n");

    }
     return 0;
}
