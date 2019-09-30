#include<stdio.h>
int main()
{
    int test,i, b, a, t, w;
    int total, j;
    char ch;

    scanf("%d", &test);

    for(i = 1; i <= test; i++){

        scanf("%d",&total);//number of match
            a = 0;
            b = 0;
            w = 0;
            t = 0;


        for(j = 1; j <= total + 1; j++){

            scanf("%c",&ch);

            if(ch == 'B'){
                b = b + 1;
            }
            else if(ch == 'W'){
                w = w + 1;
            }
            else if(ch == 'A'){
                a = a +1;
            }
            else if (ch=='T'){
                t = t + 1;
            }
            else{};
        }
        printf("Case %d: ",i);

        if(a == total)
            printf("ABANDONED\n");
        else if((b + a) == total)
            printf("BANGLAWASH\n");
        else if(w + a == total)
            printf("WHITEWASH\n");

        else if(b == w)
            printf("DRAW %d %d\n",b,t);//bd wins and ties
        else if(b > w)
            printf("BANGLADESH %d - %d\n",b,w);
        else
            printf("WWW %d - %d\n",w, b);
    }
return 0;
}
