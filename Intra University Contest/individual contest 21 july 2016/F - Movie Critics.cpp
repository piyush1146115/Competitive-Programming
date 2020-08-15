#include<bits/stdc++.h>
using namespace std;
int arr[1000000] , ans[1000000];
int main()
{
    int n,k,i,j, mx = -1, v;
    while(scanf("%d %d",&n,&k) == 2)
    {
        for(i=1; i<=n; i++)
        {
            scanf("%d",&arr[i]);
            if(arr[i] == arr[i-1])
                i-- , n--;
        }

        for(i=1; i<=n; i++)
        {
            if(arr[i-1] == arr[i+1]) ans[ arr[i] ] += 2;
            else ans[ arr[i] ]++;
        }
        v = 0;
        for(i = 1; i <= k; i++){
            if(ans[i] > ans[v]){
                v = i;
            }
        }
        printf("%d\n",v);
    }
    return 0;
}
