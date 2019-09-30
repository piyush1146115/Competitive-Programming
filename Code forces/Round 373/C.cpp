#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    scanf("%d", &n);

    if(n < 6)
    {
        printf("-1\n");

        for(int i = 1; i < n; i++)
        {
            printf("%d %d\n",i, i+1);
        }
    }
    else
    {
        printf("1 2\n");
        printf("1 3\n");
        printf("1 6\n");
        printf("2 4\n");
        printf("2 5\n");

        for(int i = 7; i <= n ; i++)
        {
            printf("%d %d\n",1, i);
        }
        for(int i = 1; i < n; i++)
        {
            printf("%d %d\n",i, i+1);
        }
    }

}
