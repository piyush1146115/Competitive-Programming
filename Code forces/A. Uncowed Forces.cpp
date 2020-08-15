#include<bits/stdc++.h>
using namespace std;
int main()
{
    double m[8], w[8];
    int i, j, k;
    int sc[] = {500, 1000, 1500, 2000, 2500};

    for(i = 0; i < 5; i++)
        scanf("%lf" , &m[i]);

    for(i = 0; i < 5; i++)
        scanf("%lf", &w[i]);

    double sum = 0;

    for(i = 0; i < 5; i++){
        sum += max(((0.3)*sc[i]), (((1 - (m[i]/250.0))* sc[i]) - 50 *w[i]));
    }
    scanf("%d %d", &i, &j);

    sum += (i * 100);
    sum -= (j * 50);

    printf("%.0lf\n", sum);
}
