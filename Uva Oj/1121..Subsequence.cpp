#include<bits/stdc++.h>
using namespace std;
int inp[100006];

int solve(int len, int mx)
{
    int ans = len + 10, high = 0, low = 0, sum = 0;

    while(high <= len){

        if(sum >= mx && low < high){
            sum -= inp[low];
            low++;
        }
        else{
            if(high != len)
            sum += inp[high];
            high++;
            //printf("%d\n", sum);
        }
          if(sum >= mx){
                //printf("ok");
            ans = min(ans, high - low);
        }
    }
       if(ans == len + 10){
            ans = 0;
        }
        return ans;
}

int main()
{
    int i, res, n, mx;

    while(scanf("%d %d",&n, &mx) == 2){
        for(i = 0; i < n; i++){
            scanf("%d", &inp[i]);
        }
       res = solve(n, mx);
        printf("%d\n", res);
    }
    return 0;
}
