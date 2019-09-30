#include<bits/stdc++.h>
using namespace std;
int p[1005];
int w[105];
int mw[105];
int main()
{
    int test, n, wg, g, i, a, b, indx1, indx2, sum;

    scanf("%d", &test);

    for(i = 1; i <= test; i++){
        scanf("%d", &n);
        sum = 0;


        for(a = 0; a < n; a++){
            scanf("%d %d", &p[a], &wg);

            w[p[a]] = wg;
        }
        indx1 = a - 1;
        sort(p, p + a);

        scanf("%d", &g);

        for(a = 0 ; a < g; a++){
            scanf("%d", &mw[a]);
        }

        indx2 = a -1;

        sort(mw, mw + a);

        for(a = indx2; a >= 0; a--){
            for(b = indx1; b >= 0; b--){
                    if(mw[a] >= w[p[b]]){
                        mw[a] -= w[p[b]];
                        sum += p[b];
                }
            }
        }

        printf("%d\n", sum);
    }
    return 0;
}
