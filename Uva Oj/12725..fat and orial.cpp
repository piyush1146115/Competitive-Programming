#include<stdio.h>
int main()
{
    double s, m, n, a, b, t_grade, o_grade, dif, answer;
    int test, i, j;

    scanf("%d", &test);

    for(i = 1; i <= test; i++)
    {
        scanf("%lf %lf %lf %lf",&m, &n, &a, &b);

        s = a + b;
        t_grade = n * s;
        o_grade = m * a;

        dif = t_grade - o_grade;
        answer = dif / b;

        if(answer > 10.0 || answer < 0.0)
            printf("Case #%d: Impossible\n",i);
        else
            printf("Case #%d: %.2lf\n",i, answer);

    }
    return 0;
}
