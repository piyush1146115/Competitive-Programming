#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAX 200005

ll ara[MAX];

int main()
{
    ll n;
    scanf("%I64d",&n);

    for(int i = 0; i < n; i++){
        scanf("%I64d", &ara[i]);
    }

    if(n == 1){
        printf("0\n");
    }
    else{
        ll lf = 0, rh = n - 1, sum1 = 0, sum2 = 0;
        ll mx = 0;
        sum1 = ara[lf];
        sum2 = ara[rh];

        while(lf < rh){
            if(sum1 == sum2){
                mx = max(mx, sum1);
                lf++;
                rh--;
                sum1 += ara[lf];
                sum2 += ara[rh];
            }
            else if(sum1 < sum2){
                lf++;
                sum1 += ara[lf];
            }
            else{
                rh--;
                sum2 += ara[rh];
            }
        }

        printf("%I64d\n",mx);

    }
}
