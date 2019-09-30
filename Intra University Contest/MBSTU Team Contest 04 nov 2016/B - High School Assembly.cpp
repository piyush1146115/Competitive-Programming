#include<bits/stdc++.h>
using namespace std;
int main()
{
    int test, i, k, n, j, ans, tc = 0;

    scanf("%d",&test);

    while(test--){
        scanf("%d",&n);

        k = 1;
        ans = 0;

        for(i = 0; i < n; i++)
        {
            scanf("%d", &j);
            if(j == k)
            {
                //cout << j << endl;
                ans++;
                k++;
            }
        }

        ans = n - ans;
        printf("Case %d: %d\n", ++tc, ans);
    }
    return 0;
}
