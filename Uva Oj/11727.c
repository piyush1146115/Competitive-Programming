#include<stdio.h>
int main()
{
    int test, a, b, c, i = 0, temp;

    scanf("%d", &test);

    while(test--)
    {
        i++;
        scanf("%d %d %d", &a, &b, &c);
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
        if(b < c){
            temp = b;
            b = c;
            c = temp;
        }

    printf("Case %d: %d\n", i, b);
    }
return 0;

}
