#include<stdio.h>
#include<math.h>
int main()
{
    int a, b,c,temp;
    float sq,i;
    while(scanf("%d %d %d",&a,&b,&c) == 3 && a != 0 && b != 0 && c != 0){

    if(b > a){
        temp = b;
        b = a;
        a = temp;
    }
    if(c > a){
        temp = c;
        c = a;
        a = temp;
    }
    sq = sqrt(b*b + c*c);
    if(a == sq){
        printf("right\n");
    }
    else{
        printf("wrong\n");
    }
    }
return 0;
}
