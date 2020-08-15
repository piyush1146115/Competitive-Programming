#include<stdio.h>
int main()
{
    float a, b, r, l, w, x, y;
    int test, count = 0;

    scanf("%d",&test);

    while(test--){
            count++;
        scanf("%f",&r);

        l = 5.0 * r;
        w = .6 * l;
        a = .45 * l;
        x = .55 * l;
        y = w / 2.0;

        printf("Case %d:\n",count);

        printf("-%.0f %.0f\n",a, y);
        printf("%.0f %.0f\n",x, y);
        printf("%.0f -%.0f\n",x, y);
        printf("-%.0f -%.0f\n",a, y);
    }

    return 0;
}
