#include<stdio.h>
#include<math.h>

int main()
{
    int test;
    float x, y, z, r, a, max, min;

    scanf("%d", &test);

    while(test--){
        scanf("%f %f %f",&x, &y, &r);

        a = sqrt(x*x + y*y);
        max = a + r;
        min = r - a;

        printf("%.2f %.2f\n",min,max);
    }
    return 0;
}
