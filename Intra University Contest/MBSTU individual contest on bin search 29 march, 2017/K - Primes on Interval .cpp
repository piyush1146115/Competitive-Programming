#include<bits/stdc++.h>
using namespace std;
#define mxx 1000005

int sum[mxx], prime[mxx];
int a, b, k;
void sieve(int n)
{
    n++;

    for(int i = 3; i * i <= n; i+= 2){
        if(prime[i] == 0){
        for(int j = i*i; j <= n; j += i * 2){
         prime[j] = 1;
        }
        }
    }
    for(int i = 4; i <= n; i+= 2)
        prime[i] = 1;

    prime[1] = prime[0] =1;
    int cnt = 0;
    for(int i = 0; i <= n; i++){
        if(prime[i] == 0)
            cnt++;

        sum[i] = cnt;
    }
}

bool bin_ser(int l)
{
 int ans = 9000000;
    for(int i = a + l; i <= b; i++){
        int res = sum[i] - sum[i - l - 1];
        ans = min(ans, res);
    }
    if(ans < k)
        return false;
    else
        return true;
}

int main()
{
    scanf("%d %d %d", &a, &b, &k);
    sieve(b + 1);

    //cout << sum[b] - sum[a - 1] << endl;
    //getchar();

    if(sum[b] - sum[a - 1] < k){
        printf("-1\n");
    }
    else{
    int lo = 0, hi = b, ans;
    while(lo <= hi){
        int mid = (lo + hi)/2;
        if(bin_ser(mid)){
            hi = mid - 1;
            ans = mid;
        }
        else
            lo = mid + 1;
    }
    printf("%d\n",ans  + 1);
    }
}
