#include<stdio.h>
int main()
{
    int n,k,p,a,b,pos,test;
    scanf("%d",&test);
    for(b = 1;b <= test;b++){
    scanf("%d %d %d",&n,&k,&p);
    pos = k;
    for(a = 1; a <= p; a++){

        if(pos == n){
            pos = 0;
        }
        pos++;
    }
    printf("Case %d: %d\n",b,pos);
    }
    return 0;
}
