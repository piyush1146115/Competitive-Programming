#include<bits/stdc++.h>
using namespace std;
int n, m;
int ara1[1005], ara2[1005];

int bin(int v)
{
 int lo = 0, hi = n - 1, ans= 9999999;

 while(lo <= hi){
    int mid = (lo + hi)/2;
    ans = min(ans, abs(ara1[mid] - v));
    if(ara1[mid] == v){
        break;
    }
    else if(ara1[mid] < v){
        lo = mid + 1;
    }
    else{
        hi = mid - 1;
    }

 }
 return ans;
}



int main()
{
    int test;

    scanf("%d", &test);

    for(int tc = 1; tc <= test; tc++){
      scanf("%d", &n);
      for(int i = 0; i < n; i++)
        scanf("%d", &ara1[i]);

      scanf("%d", &m);
      for(int i = 0; i < m; i++)
        scanf("%d", &ara2[i]);

       sort(ara1, ara1 + n);
       int ans = 9999999;


       for(int i = 0; i < m; i++){
        ans = min(ans, bin(ara2[i]));
       }


       printf("%d\n",ans);
    }
}
