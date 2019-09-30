#include<bits/stdc++.h>
using namespace std;
int main()
{
    int x[3], y[3], c[3], r, L, W, H, dis, test;

    scanf("%d", &test);

    while(test--){
        scanf("%d %d %d %d %d %d %d",&x[1], &y[1], &x[2], &y[2], &c[1],&c[2], &r);
        L = x[2] - x[1];
        W = y[2] - y[1];
        dis = c[1] - x[1];
        H = c[2] - y[1];

        if((6 * L == 10 * W) && (5 * r == L) && (dis * 20 == L * 9) && (H * 2 == W))
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}
