#include<bits/stdc++.h>
using namespace std;

int n, k;
int ara[100005];

bool chk(long long v)
{
    int m = 0;
    for(int i = 0; i < n; i++){
        if(ara[i] > v)
            return false;
        if(ara[i] + ara[i + 1] <= v){
            i++;
            m++;

        }
        else if(ara[i] <= v){
            m++;
        }
    }
    if(m <= k)
        return true;
    else
        return false;
}


int main()
{
    scanf("%d %d", &n, &k);
    long long lo  = 0, hi = 0;


    int ans = 0;
    for(int i = 0; i < n; i++){
        scanf("%d", &ara[i]);
        ans = max(ans, ara[i]);
    }
/*
    while(lo <= hi){
         //   cout << lo << " " << hi << endl;
        long long mid = (lo + hi)/2;
        if(chk(mid)){
            ans = mid;
            hi = mid -  1;
        }
        else{
            lo = mid + 1;
        }
    }
*/
    int m = 2 * k;
    int dif = m - n;

    for(int i = 0; i < (k - dif); i++){
        ans = max(ans, (ara[i] + ara[n - dif - 1 - i]));
    }
    cout << ans << endl;
}
