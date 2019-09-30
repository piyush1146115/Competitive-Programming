#include<iostream>
#include<cstdio>

using namespace std;
int main()
{
    int ara[10];
    int a, b, c, d, i, j, k, m, n, count, flag;

    while(scanf("%d %d",&m, &n) == 2){
    count = 0;
    for(a = m; a <= n; a++){
        for(c = 0; c < 10; c++)
            ara[c] = 0;

        flag = 0;
        i = a;
        while(i >= 1){
            b = i % 10;
            i = i / 10;
            ara[b]++;
            if(ara[b] > 1){
                flag = 1;
                break;
            }
        }
        if(flag == 0){
            count++;
        }
    }
    printf("%d\n",count);
    }
    return 0;
}
