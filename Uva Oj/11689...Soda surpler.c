#include<stdio.h>
int main()
{
    int  a, b, c, i, j, k, rem, sum, total,test, x;

    scanf("%d",&test);

    for(x = 1; x <= test; x++)
    {
        scanf("%d %d %d", &a, &b, &c);

        sum = a + b;
        total = sum/c;
        rem = sum % c;
        i = total;
        while(i >= 1){
            j = i + rem;
            k = j/c;
            total = total + k;
            rem = j % c;
            i = k;
        }

        printf("%d\n",total);
    }
    return 0;
}
