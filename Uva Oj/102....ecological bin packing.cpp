#include<stdio.h>
int main()
{
    int b1, g1, c1, b2, g2, c2, b3, g3, c3;
    int x, y, z, a, b, c, count;
    char str[5];

    while(scanf("%d %d %d %d %d %d %d %d %d",&b1, &g1, &c1, &b2, &g2, &c2, &b3, &g3, &c3) == 9){
        count = 0;
        if(b1 > b2 && b1 > b3){
            x= b1 - b2;;
            y = b1 - b3;
            count += (x + y);
            str[0] = 'B';
        }

        else if(b2 > b1 && b2 > b3){
            x = b2 - b1;
            y = b2 - b3;
            count += (x + y);
            str[1] = 'B';
        }
        else{
            x = b3 - b1;
            y = b3 - b2;
            count += (x + y);
            str[2] = 'B';
        }
        printf("%d\n",count);
        /*if(g1 > g2 && g1 > g3){
            x = g1 - g2;
            y = g1 - g3;
            count += (x + y);
            str[0] = 'G';
        }
        else if(g2 > g3 && g2 > g1){
            x = g2 - g1;
            y = g2 - g3;
            count += (x + y);
            str[1] = 'G';
        }
        else{
            x = g3 - g1;
            y = g3 - g2;
            count += (x + y);
            str[2] = 'G';
        }
        if(c1 > c2 && c1 > c3){
            x  = c1 - c2;
            y = c1 - c3;
            count += (x + y);
            str[0] = 'C';
        }
        else if(c2 > c3 && c2 > c1){
            x = c2 - c3;
            y = c2 - c1;
            count += (x + y);
            str[1] = 'C';
        }
        else{
            x = c3 - c1;
            y = c3 - c2;

            count += (x + y);
            str[2] = 'C';
        }
        for(a = 0; a < 2; a++){
            printf("%c",str[a]);
        }
    }*/
}
    return 0;
}
