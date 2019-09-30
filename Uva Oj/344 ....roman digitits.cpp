#include<stdio.h>
int main()
{
    int num, i, v, l, c, j, a, b, k, sum, x, div;

    while(scanf("%d",&num) == 1 && num != 0){
            i = 0;
            v =0;
            x = 0;
            c = 0;
             l = 0;

        // for i

        div = num /10;

        i = div * 14;

        j = num - (div * 10);

        sum = 0;
        k = 0;
        for(a = 1; a <= j; a++){
            k++;
            if(a == 5){
                k = 0;
            }
            sum = sum + k;
            if(k == 3){
                k = 0;
            }
        }
         i = i + sum;

         // calculating v

         v = div * 5;
        k = 0;
         if(j >= 4){
            k = j - 4 + 1;

            if(j == 9)
                k--;
         }
         v = v + k;


         // calculating x

         x = div * 2;

         if(j == 9)
            x++;

         sum = 0;
         k = 1;

         for(a = 11; a <= num; a++){

            if(a == 21 || a == 71){
                k = 2;
            }
            else if(a == 31 || a == 81){
                k = 3;
            }
            else if(a == 40 || a == 50 || a == 90 || a == 100){
                k = 0;
            }
            else if( a == 41 || a == 61 ||  a == 91){
                k = 1;
            }
            sum = sum + k;
         }
         x = x + sum;
        if(num >= 50){
            x--;
            if(num == 100)
                x--;
        }
         // calculating l

         if(num >= 40){
            l =  num - 40 + 1;
            if(num >= 89){
                b = num - 89;
                l = l -b;
            }
         }

         //calculating c

         if(num >= 90 && num <= 100)
            c = num - 90 + 1;


         printf("%d: %d i, %d v, %d x, %d l, %d c\n",num, i, v, x, l, c);
    }
    return 0;
}
