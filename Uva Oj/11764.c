#include<stdio.h>
int main()
{
    int a, b, c, d,n,h,l,test;
    int ara[55];

    scanf("%d",&test);

    for( b = 1; b <= test; b++){
    scanf("%d",&n);
    h = 0;
    l = 0;
    for(a = 0; a < n;a++){
        scanf("%d",&ara[a]);
    }

    for(a = 0; a < n-1; a++){
        if(ara[a+1] > ara[a] ){
          h++;
        }
        if(ara[a + 1] < ara[a]){
            l++;
        }
    }
    printf("Case %d: %d %d\n",b,h,l);
}
return 0;
}
