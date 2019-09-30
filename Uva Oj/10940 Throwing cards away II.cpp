#include<bits/stdc++.h>
using namespace std;
int main()
{
    int i, j, k, n, sum;

    while(scanf("%d", &n) == 1){
        if(n == 0)
            break;

        k = 1;

        while(1){
            if(k == n){
                printf("%d\n", k);
                break;
            }
            else if(k > n){
                k = k / 2;
                j = n - k;
                printf("%d\n", j* 2);
                break;
            }
            k *= 2;
        }
    }

    return 0;
}
