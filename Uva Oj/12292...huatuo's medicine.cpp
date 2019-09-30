#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n, res, test, i;
    cin >> test;

    for(i = 1; i <= test; i++){
            scanf("%d", &n);

            res = (n - 1) * 2 + 1;

            printf("Case #%d: %d\n",i ,res);
    }
    return 0;
}
