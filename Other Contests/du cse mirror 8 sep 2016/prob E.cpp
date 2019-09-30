#include<bits/stdc++.h>
using namespace std;
int c[100005];
int main()
{
    int n, x, test, low, high, mid, i, j, cs = 0;

    scanf("%d",&test);

    while(test--){
        scanf("%d %d",&n, &x);

        for(i = 1; i <= n; i++){
            scanf("%d",&c[i]);
        }

        low = 1;
        high = 100000;


        while(low <= high){
        mid = (low + high) / 2;
            int sum = 0;
            for(i = 1; i <= n; i++){
                sum += (c[i]/ mid);
            }
            if(sum < x){
                high = mid - 1;
            }
            else if(sum > x){
                low = mid + 1;
            }
            else if(sum == x){
                break;
            }
        }
        printf("Case %d: %d\n",++cs, mid*x);
    }
    return 0;
}
