#include<bits/stdc++.h>

using namespace std;

int main()
{
    unsigned long long sum;
    int n, i, j;

    while(scanf("%d",&n) == 1 && n != 0){
            sum = 0;
        for(i = 1; i <= n; i++){
            sum += i * i;
        }
        printf("%llu\n",sum);
    }

    return 0;
}
