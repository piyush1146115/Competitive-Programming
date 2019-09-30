#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n, i;

    scanf("%d", &n);

    if(n <= 2)
        printf("-1");
    else{
        for(i = n; i >= 1; i--)
            printf("%d ",i);

        printf("\n");
    }
}
