#include<stdio.h>
int main()
{
    int test, x, y, i;
    float a, b;

    scanf("%d", &test);

    for(i = 1; i <= test; i++){
        scanf("%d %d",&x, &y);

        if(x >= 1 && y == 0){
            a = 1.0;
            b = 0.0;
        }
        else if(y == 1 && x == 0){
            a = 0.0;
            b = 1.0;
        }
        else if(x >= 0 && y % 2 == 0){
            a = 1.0;
            b = 0.0;
        }
        else if(x >= 0 && y % 2 != 0){
            a = 0.0;
            b = 1.0;
        }

        printf("Case %d: %.3f %.3f\n",i, a, b);
    }
    return 0;
}
