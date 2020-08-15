#include<stdio.h>
int main()
{
    long long int n,a,num;
    int index,i;
    int ara[100] = {0};


        while(scanf("%lld",&n) == 1 && n >= 0){
                num = n;
                if(n == 0){
                printf("0\n");
            }
            else if(n < 0){
            printf("yes");
            }
        else{
            index = 0;
        while(num  != 0){
            ara[index] = num % 2;
            index++;
            num = num/2;
        }
        for( a = index-1;a >= 0; a--){

            printf("%d",ara[a]);
        }
        printf("\n");
    }

}
return 0;
}
