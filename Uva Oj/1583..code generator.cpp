#include<bits/stdc++.h>
using namespace std;
int res[1000000];
void f()
{
    int i, j, k, sum;

    for(i = 1; i <= 100000; i++){
        sum = i;
        j = i;
        while(j != 0){
            sum += (j % 10);
            j = j / 10;
        }
        if(res[sum] == 0){
            res[sum] = i;
        }
    }
}
int main()
{
    f();
    int i, t, n;

    scanf("%d", &t);

    while(t--){
        scanf("%d", &n);
        printf("%d\n",res[n]);
    }
    return 0;
}
