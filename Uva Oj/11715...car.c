/*
If 1 u v t are given then print s and a
If 2 u v a are given then print s and t
If 3 u a s are given then print v and t
If 4 v a s are given then print u and t*/
#include<stdio.h>
#include<math.h>
int main()
{
    int a, j = 0;
    double  b, c, d, res1, res2,i;

    for( ; ;){
    scanf("%d", &a);
    if(a == 0)
        break;
    scanf("%lf %lf %lf", &b, &c, &d);
        j++;
        switch(a)
        {
        case 1:
            res2 = (c - b)/d;
            res1 = b*d + 0.5*res2*d*d;
            break;
        case 2:
            res2 = (c - b)/d;
            res1 = b*res2 + 0.5*d*res2*res2;
            break;
        case 3:
            i = b*b + 2*c*d;
            res1 = sqrt(i);
            res2 = (res1 - b)/c;
            break;
        default:
            i = b*b - 2*c*d;
            res1 = sqrt(i);
            res2 = (b - res1)/c;
        }
        printf("Case %d: %0.3lf %0.3lf\n", j, res1, res2);
    }
    return 0;
}
