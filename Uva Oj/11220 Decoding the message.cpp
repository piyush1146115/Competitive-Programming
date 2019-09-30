#include<bits/stdc++.h>
using namespace std;
int main()
{
    string s, st, ans;
    int i, j, k, co, test;

    scanf("%d\n",&test);
int cs = 0;
    while(test--){
            printf("Case #%d:\n", ++cs);
        while(getline(cin, s) && s.size() > 0){
            co = 1;
            stringstream ss(s);

            while(ss >> st){
                if(st.size() >= co){
                    ans.push_back(st[co - 1]);
                    co++;
                }
            }
            cout << ans << endl;
            ans.clear();
        }
        if(test)
        printf("\n");
    }
    return 0;
}
