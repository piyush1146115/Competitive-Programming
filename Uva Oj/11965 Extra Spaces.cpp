#include<bits/stdc++.h>
using namespace std;
int main()
{
    string st[55], ans[55];
    int i, j, k, test, cs = 0, n;
    //freopen("input.txt", "r", stdin);
    scanf("%d", &test);

    while(test--){
        scanf("%d", &n);
        getchar();
        for(i = 0; i < n; i++){
            getline(cin, st[i]);
        }

        for(i = 0; i < n; i++){
            for(j = 0; j < st[i].size(); j++){
                if(st[i][j] == ' '){
                    ans[i].push_back(st[i][j]);
                    while(st[i][j] == ' ' && j < st[i].size()){
                        j++;
                    }
                    j--;
                }
                else{
                    ans[i].push_back(st[i][j]);
                }
            }
        }

        printf("Case %d:\n",++cs);

        for(i = 0; i < n; i++)
            cout << ans[i] << endl;

        if(test)
            printf("\n");

        for(i = 0; i < 52; i++){
            st[i].clear();
            ans[i].clear();
        }
    }
    return 0;
}
