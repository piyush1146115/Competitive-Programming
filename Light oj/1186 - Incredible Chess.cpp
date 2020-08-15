#include<bits/stdc++.h>
using namespace std;
int ar1[105], ar2[105];
int main() {
    int test;
    scanf("%d", &test);

    for (int tc = 1; tc <= test; tc++) {
        int n;
        scanf("%d", &n);

        for (int i = 0; i < n; i++)
            scanf("%d", &ar1[i]);

        for (int i = 0; i < n; i++)
            scanf("%d", &ar2[i]);

        int ans = 0;

        for (int i = 0; i < n; i++) {
            int dif = ar2[i] - ar1[i] - 1;
            ans ^= dif;
        }
        if (ans)
            printf("Case %d: white wins\n", tc);
        else
            printf("Case %d: black wins\n", tc);
    }
}
