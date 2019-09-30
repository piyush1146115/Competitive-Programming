#include<bits/stdc++.h>
using namespace std;

int f(int n, int k)
{
    int i, j, s = 0;

    for(i = 1; i <= n; i++)
        s = (s + k) % i;

    return s + 1;
}

int main()
{
    int  test, n, k, ans, i;

    scanf("%d", &test);

    for(i = 1; i <= test; i++){
        scanf("%d %d",&n, &k);

        ans = f(n, k);
        printf("Case %d: %d\n", i, ans);
    }
    return 0;
}
