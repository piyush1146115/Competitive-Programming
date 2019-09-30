#include<stdio.h>
#include<math.h>
int main()
{
    unsigned long long int n;



    while(scanf("%llu",&n) == 1){

        printf("%llu\n",(n*n*(n+1)*(n+1))/4);
    }
 return 0;
}
