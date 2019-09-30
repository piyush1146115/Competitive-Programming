#include<bits/stdc++.h>
using namespace std;
int main()
{
    int test, c = 0, sum = 0, y, l;

    scanf("%d",&test);

    while(test--){
        sum = 0;
        c++;
        scanf("%d %d",&y, &l);
        sum += abs(y - l);
        sum += abs(y - 0);
        sum *= 4;
        printf("Case %d: %d\n",c, sum + 19);
    }
    return 0;
}
