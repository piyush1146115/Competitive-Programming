#include<bits/stdc++.h>
using namespace std;
#define ll long long
vector<ll> inc, decc;

int mp[100000 * 3];
int main()
{

    int n, k, flag = 1;
    //cin >> n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        //cin >> k;
        scanf("%d", &k);

        mp[k]++;
        if(mp[k] == 1){
            inc.push_back(k);
        }
        if(mp[k] == 2){
            decc.push_back(k);
        }
        if(mp[k] > 2){
            flag = 0;
        }
    }


    if(flag == 0){
        printf("NO\n");
    }else{
        printf("YES\n");

        printf("%d\n",inc.size());
        sort(inc.begin(),inc.end());

        for(int i = 0; i < inc.size(); i++){
            printf("%d ",inc[i]);
        }
        printf("\n");

        printf("%d\n",decc.size());
        sort(decc.begin(),decc.end());
        reverse(decc.begin(),decc.end());

        for(int i = 0; i < decc.size(); i++){
            printf("%d ",decc[i]);
        }
        printf("\n");
    }

}
