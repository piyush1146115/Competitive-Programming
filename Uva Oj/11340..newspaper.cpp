#include<bits/stdc++.h>
using namespace std;

int main()
{
    //freopen("input.txt", "r", stdin);

    int i, j, k, m, test, a, b, len;
    char ch, str[10100];
    double total, sum, n, value[260];

    scanf("%d", &test);

    for( i = 1; i <= test; i++){
            sum = 0;
        memset(value, 0, sizeof(value));

        scanf("%d", &k);
        getchar();
        for( j = 1; j <= k; j++){
            scanf("%c %lf", &ch, &n);
             getchar();

            value[ch] = n/ 100.0;

           // printf("%d\n", value[ch]);
        }

        scanf("%d", &m);
        getchar();

        for(a = 0; a < m; a++){
            gets(str);

            len = strlen(str);

            for(b = 0; b < len; b++){
                sum += value[str[b]];
            }
        }

        sum += 1e-9;
        printf("%0.2lf$\n",sum);
    }

    return 0;
}
