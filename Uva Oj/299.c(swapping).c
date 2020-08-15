#include<stdio.h>
int main()
{
    int test, lenth, per[50], a, b, count;
    int temp, i, j;
    scanf("%d", &test);

    for( a = 0; a < test; a++ )
    {
        scanf("%d", &lenth);
        count = 0;
        for( b = 0; b < lenth; b++)
        {
            scanf("%d", &per[b]);
        }

        for( i = 0; i < lenth  - 1 ; i++)
        {
            for(j = i +1; j < lenth ; j++)
            {
                if(per[i] > per[j])
                {
                    temp = per[j];
                    per[j] = per[i];
                    per[i] = temp;
                    count++;
                }
            }
        }

        printf("Optimal train swapping takes %d swaps.\n", count);


    }
    return 0;
}

