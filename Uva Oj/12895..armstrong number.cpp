#include<stdio.h>
#include<math.h>
int main()
{
    double d;
    unsigned long long sum, n, i, j, k;
    int test, a, b, ara[15],p;

    scanf("%d",&test);

    while(test--){
        scanf("%llu",&n);
        j = n;
        k = 0;
        p = 0;
        while(j >= 1){
            a = j % 10;
            ara[k++] = a;
            j = j / 10;
            p++;
        }
        sum = 0;
    for(i = 0; i < p; i++){
        d = pow(ara[i], p);
        sum += d;
    }

    if(sum == n){
        printf("Armstrong\n");
    }
    else{
        printf("Not Armstrong\n");
    }
    }
    return 0;

}
