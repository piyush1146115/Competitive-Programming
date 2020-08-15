#include<stdio.h>
int main()
{
    unsigned long long n, m, sum, fin;

    while(scanf("%llu",&n) == 1)
    {
        m = ((n - 1) / 2) + 1;

        sum = m  * ((2 + (m - 1) * 2) / 2);

        fin = (2 * (sum -1) + 1) + (2 * (sum - 2) + 1) + (2 * (sum - 3) + 1);

        printf("%llu\n",fin);
    }
    return 0;
}
