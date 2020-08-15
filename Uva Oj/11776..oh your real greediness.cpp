#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long s[1005], e[1005];
    int n, i, j, flag[1005], t = 0;

    while(scanf("%d", &n) == 1){
        if(n == -1)
            break;

            memset(flag, 0, sizeof(flag));

        t++;
        for(i = 0; i < n; i++)
            scanf("%lld %lld", &s[i], &e[i]);
        int c = 0, d, m = 0;
        for(i = 0; i < n; i++){
                d = 0;
                c = 0;
            for(j = 0; j < n; j++){
                if(e[i] >= s[j] && e[i] <= e[j]){
                    d++;
                }
                if(s[i] >= s[j] && s[i]<= e[j])
                    c++;
            }
            c = max(c, d);
            m = max(c, m);
        }
        printf("Case %d: %d\n", t, m);
    }
    return 0;
}
