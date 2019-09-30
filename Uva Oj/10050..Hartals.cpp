#include<stdio.h>
int main()
{
    int test, count, a, i, j, party, n;
    int p[150], days[4000];

    scanf("%d", &test);

    while(test--){
        count = 0;
        scanf("%d",&n);
         scanf("%d", &party);

        for(a = 1; a <= party; a++){
            scanf("%d", &p[a]);
        }

        for(a = 1; a <= n; a++)
            days[a] = 0;

        for(i = 1; i <= party; i++)
        for(j = p[i]; j <= n; j += p[i]){
            days[j] = 1;
        }

        for(a = 1; a <= n ; a++){
        if((a + 1) % 7 != 0 && a % 7 != 0){
            if(days[a])
                count++;
        }
        }
        printf("%d\n",count);
    }
    return 0;
}
