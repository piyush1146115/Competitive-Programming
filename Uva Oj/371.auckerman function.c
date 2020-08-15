#include<stdio.h>
int main()
{
   unsigned long long int a, b, x, d, i, j, c , max, min;

    while(scanf("%llu %llu", &i, &j) == 2 && (i != 0 || j != 0)){
            if(i >= j){
                max = i;
                min = j;
            }
            else{
                min = i;
                max = j;
            }
    c = 0;

    for( a = min; a <= max; a++ ){
             b = 0;
            if( a == 1){
                b = 3;
            }
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
        if( b > c){
            c = b;
            d = a;
        }
    }

   printf("Between %llu and %llu, %llu generates the longest sequence of %llu values.\n" , min , max, d, c);

    }
return 0;
}
