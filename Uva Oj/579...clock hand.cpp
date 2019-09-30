#include<stdio.h>
#include<math.h>
int main()
{
    float h, m, dif, angle, a, b;

    while(scanf("%f:%f",&h, &m) == 2 && (h != 0 || m != 0)){

    if(h == 12){
        h = 0;
    }

    h = h + (m / 60.0);
    m = m / 5.0;

    dif = fabs(m - h);

    if(dif > 6){
        dif = 12 - dif;
    }

   angle = dif * 30.0;

    printf("%.3f\n",angle);

    }
    return 0;
}
