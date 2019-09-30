#include<stdio.h>
#include<math.h>
unsigned long long status[2147483655];
int main()
{
    long long n, a, b, c, i, j, k,count,left;
    long long m[20];


    while(scanf("%lld %lld",&n,&k) == 2){
            count =0;
        for(i = 0;i < k;i++){
            scanf("%lld",&m[i]);
        }
        for(i = 0;i <= n; i++){
            status[i] = 0;
        }
        for(a = 0;a <= k; a++){
            for(b = m[a]; b <= n;b += m[a]){
                if(status[b] == 0){
                status[b] = 1;
                count++;
                }
            }
        }
    left = n - count;
    printf("%lld\n",left);
    }
    return 0;
}
