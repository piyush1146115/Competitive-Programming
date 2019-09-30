#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long fact[15], i, j, sum = 1, n, pro[15];


    for(i = 1; i <= 12; i++){
        sum *= i;
        fact[i] = sum;
    }
    pro[2] = 1;
    pro[3] = 2;
    for(i = 4; i <= 12; i++){
        pro[i] = (i - 1) * (pro[i -1] + pro[i - 2]);
    }
    int test;

    scanf("%d", &test);

    while(test--){
        scanf("%lld", &n);

        printf("%lld/%lld\n",pro[n], fact[n]);
    }
    return 0;
}
