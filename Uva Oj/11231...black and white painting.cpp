#include<stdio.h>
int main()
{
    int a, b, c, res;

    while(scanf("%d %d %d", &a, &b, &c) == 3 && (a != 0 || b != 0 || c != 0)){
        if(a < 8 || b < 8)
        res = 0;
        else if(c == 1){
            res = ((a - 7) * (b - 7) + 1 )/ 2;
        }
        else{
            res = ((a - 7) * ( b - 7))/2;
        }
        printf("%d\n",res);
    }
    return 0;
}
