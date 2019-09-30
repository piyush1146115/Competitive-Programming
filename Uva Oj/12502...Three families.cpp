#include<stdio.h>

int main()
{
    float a, b, c, d, e, f ,avg;
    float money, fin;
    int test;

    scanf("%d",&test);

    while(test--){
    scanf("%f %f %f",&a , &b, &money);

    avg = (a + b)/3;

    c = a - avg;
    d = b - avg;
    e = c + d;
    if(c == 0){
        fin = 0;
    }
    else if(d == 0){
        fin = money;
    }
    else{
        fin = (money * c) / e;
    }


    printf("%.0lf\n",fin);
    }

    return 0;
}
