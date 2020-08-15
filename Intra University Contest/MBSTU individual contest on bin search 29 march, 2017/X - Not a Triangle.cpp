
#include<bits/stdc++.h>
using namespace std;
int ara[2005];
    int n;

int ser(int v)
{

    int lo = 0, hi = n - 1;
    int ans = -1;
    while(lo <= hi){
        int mid = (lo + hi)/2;
        if(ara[mid] <= v){
            lo = mid + 1;
        }
        else{
            ans = mid;
            hi= mid - 1;
        }
    }
    return ans;
}
int main()
{
    while(scanf("%d", &n) == 1 && n != 0){
        for(int i = 0; i < n; i++)
            scanf("%d", &ara[i]);

        int cnt = 0;
        sort(ara, ara + n);

        for(int i = 0; i < n - 1; i++){
            for(int j = i + 1; j < n; j++){
            int ans = ser(ara[i] + ara[j]);
            if(ans  != -1){
                cnt += (n - ans);
            }
           // cout << ans << " " << (ara[i] + ara[j]) << endl;
            }
        }
        printf("%d\n",cnt);
    }

}
