#include<stdio.h>
int main()
{
    unsigned long long a, b, c;
    int d,t;

    scanf("%d",&t);

    for(d = 1; d <= t;d++){
    scanf("%llu %llu %llu",&a,&b,&c);

    if((a+b) > c && (b+c) > a && (c+a) > b){
        if(a==b && b==c){
            printf("Case %d: Equilateral\n",d);
        }
        else if(a==b|| b==c || c==a){
            printf("Case %d: Isosceles\n",d);
        }
        else{
            printf("Case %d: Scalene\n",d);
        }
    }
    else{
        printf("Case %d: Invalid\n",d);
    }
    }
return 0;
}
