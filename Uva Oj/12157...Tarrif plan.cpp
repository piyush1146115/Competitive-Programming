#include<stdio.h>
int main()
{
    int a, b, c, M, m, j, J, test, n;

    scanf("%d",&test);

    for(a = 1; a <= test;a++){
        J = 0;
        M = 0;
        scanf("%d",&n);

        for(b = 1; b <= n;b++){
            scanf("%d",&c);
            m = c / 30;
            j = c / 60;
            M += (m + 1) * 10;
            J += (j + 1) * 15;
        }
        if( M < J){
            printf("Case %d: Mile %d\n",a, M);
        }
        else if( J < M){
            printf("Case %d: Juice %d\n",a, J);
        }
        else if(J == M){
            printf("Case %d: Mile Juice %d\n",a,M);
        }
   }
   return 0;
}
