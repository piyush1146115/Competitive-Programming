#include<bits/stdc++.h>
using namespace std;
long long ara[100005], dif[100005];
int main()
{
    long long n, i, k, mx, j, ind, test, cs = 0;

    scanf("%lld", &test);

    while(test--){
        scanf("%lld", &n);

        scanf("%lld",&ara[0]);
        dif[0] = ara[0];
        mx = ara[0];
        ind = 0;
        for(i = 1; i < n; i++){
            scanf("%lld",&ara[i]);
            dif[i] = ara[i] - ara[i - 1];
            if(dif[i] > mx){
                mx = dif[i];
                ind = i;
            }
        }
        ind++;
        int flag = 1;
        k = mx - 1;

        while(ind < n){
            if(dif[ind] == k){
                k--;
                ind++;
                continue;
            }
            if(dif[ind] > k || k < 0){
                //cout << dif[ind] << " " << k << endl;
                flag = 0;
                break;
            }
            ind++;
        }
        if(flag)
            printf("Case %lld: %lld\n",++cs, mx);
        else
            printf("Case %lld: %lld\n",++cs, mx + 1);
    }
    return 0;
}
