#include<stdio.h>
int main()
{
    int a, b, c, d;

    while(scanf("%d %d %d",&a, &b, &c) == 3){
    if(a == b && b == c){
        printf("*\n");
    }
    else if(a != b && a != c){
        printf("A\n");
    }
    else if(b != a && b != c){
        printf("B\n");
    }
    else{
        printf("C\n");
    }

    }
    return 0;
}
