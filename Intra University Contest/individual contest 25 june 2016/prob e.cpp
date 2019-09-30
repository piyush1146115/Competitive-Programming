#include<bits/stdc++.h>
using namespace std;
int main()
{
    int ara[15], i, k, sum = 0, c = 0;

    scanf("%d",&k);

    for(i = 0; i < 12; i++)
        scanf("%d",&ara[i]);

    sort(ara, ara + 12);

    for(i = 11; i >= 0; i--)
    {
        sum += ara[i];
        c++;
          if(sum >= k)
            break;
    }
    if(k == 0)
        c  = 0;
    if(i == - 1)
        printf("-1\n");
    else
        cout << c << endl;

    return 0;
}
