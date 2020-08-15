#include<stdio.h>
int main()
{
    int a, b,c,index = 0, test;

    scanf("%d",&test);

    while(test--){
        scanf("%d %d %d",&a,&b,&c);
        index++;

        if(a > 20 || b > 20 || c > 20){
            printf("Case %d: bad\n",index);
        }
        else{
            printf("Case %d: good\n",index);
        }
    }
    return 0;
}
