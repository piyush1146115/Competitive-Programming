#include<stdio.h>
int main()
{
    int n, count = 0;

    while(scanf("%d",&n) == 1 && n != 0){
            count++;
        printf("Case %d: %d\n",count,n/2);
    }
    return 0;
}
