/*#include<stdio.h>
#include<math.h>
int main()
{
    unsigned long long n;
    long long sq, dif, x, y, i, j;

    while(scanf("%llu",&n) == 1 && n != 0){

        sq = sqrt(n);

        dif = n - sq*sq;

        if(dif == 0){
            if(sq % 2 == 0){
                x = sq;
                y = 1;
            }
            else{
                x = 1;
                y =sq;
            }
        }
        else{
            if(sq % 2 == 0){
                x = sq + 1;
                y = 1;

                for( i = 1; i < dif; i++){
                if(y == sq + 1){
                    x--;
                }
                if( y < sq + 1){
                    y++;
                }
            }
            }

            else{
                x = 1;
                y = sq  + 1;

                for(i =1 ;i < dif; i++){
                if( x == sq + 1){
                    y--;
                }
                if(x < sq + 1){
                    x++;
                }
                }
            }
        }
        printf("%lld %lld\n", x, y);
    }
    return 0;
}
*/
#include<stdio.h>
#include<math.h>
int main()
{
    unsigned long long n;
    long long sq, dif, x, y, i, j;
    while(scanf("%llu",&n) == 1, n){
        //scanf("%llu", &n);
        sq = sqrt(n);

        dif = n - sq*sq;

        if(dif == 0){
            if(sq % 2 == 0){
                x = sq;
                y = 1;
            }
            else{
                x = 1;
                y =sq;
            }
        }
        else{
        int hf = sq + 1;
        if(sq % 2 == 0){
            if(dif <= hf){
                x = hf;
                y = dif;
            }
            else{
                dif -= hf;
                x = (sq - dif) + 1;
                y = hf;
            }
        }
        else
        {
            hf = sq + 1;
            if(dif <= hf){
                y = hf;
                x = dif;
            }
            else{
                dif -= hf;
                y = (sq - dif ) + 1;
                x = hf;
            }
        }
        }
        printf("%lld %lld\n", x, y);

      //  printf("%lld\n",sq);
    }
    return 0;
}


