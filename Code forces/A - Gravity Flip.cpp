#include<bits/stdc++.h>
using namespace std;
int main()
{
    int ara[105], i, n;

    cin >> n;

    for(i = 0; i < n; i++)
        scanf("%d",&ara[i]);

    sort(ara, ara + n);

    for(i = 0 ; i < n - 1; i++)
        printf("%d ",ara[i]);

    printf("%d\n",ara[n - 1]);

    return 0;
}
