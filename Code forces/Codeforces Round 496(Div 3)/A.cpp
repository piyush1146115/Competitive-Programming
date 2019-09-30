#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n, ara[1005];

    scanf("%d", &n);

    for(int i = 0; i < n; i++){
        scanf("%d", &ara[i]);
    }

    vector<int> ans;
    int cnt = 1;

    for(int i = 1; i < n; i++){
        if(ara[i] <= ara[i - 1]){
            ans.push_back(cnt);
            cnt= 1;
        }
        else{
            cnt++;
        }
    }
    ans.push_back(cnt);


    printf("%d\n",ans.size());

    for(int i = 0; i < (int)ans.size(); i++){
        printf("%d ", ans[i]);
    }

}
