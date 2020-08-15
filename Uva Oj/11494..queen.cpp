#include<stdio.h>
int main()
{
    int a, b, c, d, x, y, flag = 0, move = 0;

   while (scanf("%d %d %d %d",&a, &b, &c, &d) == 4 && (a != 0 || b!= 0 || c!= 0 || d!= 0)){

    flag = 0;

    if(a == c && b == d){
        move = 0;
    }
    else if(a == c || b == d){
        move = 1;
    }
    else{
        x = a;
        y = b;

        while(x < 8 && y < 8){
            x++;
            y++;
            if(x == c && y == d){
                move = 1;
                flag = 1;
            }
        }

        if(flag != 1){
            x = a;
            y = b;

            while( x > 1 && y < 8){
                x--;
                y++;
              if(x == c && y == d){
                move = 1;
                flag = 1;
            }
            }
        }
        if(flag != 1){
            x = a;
            y = b;

            while(x < 8 && y > 1){
                x++;
                y--;

                 if(x == c && y == d){
                move = 1;
                flag = 1;
            }
            }
        }
        if(flag != 1){
            x = a;
            y = b;

            while(x > 1 && y > 1){
                x--;
                y--;

                 if(x == c && y == d){
                move = 1;
                flag = 1;
            }
            }
        }
        if(flag != 1){
            move = 2;
        }
    }
    printf("%d\n",move);
   }
    return 0;
}
