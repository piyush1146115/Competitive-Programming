#include<stdio.h>
int main()
{
    int a, b, x, i, j, c , max, min;

    while(scanf("%d %d", &i, &j) == 2){
            if(i > j){
                max = i;
                min = j;
            }
            else{
                min = i;
                max = j;
            }
    c = 0;
    for( a = min; a <= max; ++a ){
            b = 1;
            x = a;
        while(x != 1){
                ++b;
            if(x % 2 == 0){
                x = x/2;
            }
            else{
                x = 3*x + 1;
            }
        }
        if( b >= c){
            c = b;
        }
    }

   printf("%d %d %d\n" , i , j, c);

    }
return 0;
}
