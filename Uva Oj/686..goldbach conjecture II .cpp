#include<stdio.h>
int ara[35000];
int main()
{
    int i, j, k, l;
    int n, a, b, count;
    for(i = 4; i <= 33000; i += 2)
        ara[i] = 1;

    for(i = 3; i <= 183;i += 2 ){
        if(ara[i] == 0){
        for(j = i * i; j <= 33000; j += i << 1)
            ara[j] = 1;
        }
    }

    while(scanf("%d",&n) == 1 && n != 0){
        count = 0;

        for(a = n / 2; a >= 2; a--){
            if(ara[a] == 0){
                b = n - a;
                if(ara[b] == 0){
                    count++;
                }
            }
        }
        printf("%d\n", count);
    }
    return 0;
}
