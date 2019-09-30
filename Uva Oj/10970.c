#include<stdio.h>
int main()
{

    int m, n, res;

    while(scanf("%d  %d", &m, &n) == 2)
    {
        res = (m - 1) + (n -1)*m ;
        printf("%d\n", res);
    }

    return 0;

}
