#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long int ara[205], n, sum, i, j, k, test, a, b, cs = 0, cnt;


    scanf("%lld", &test);

    while(test--){
    scanf("%lld", &n);

    for(i = 0; i < n; i++)
        scanf("%lld", &ara[i]);

    scanf("%lld %lld", &a, &b);
    sort(ara, ara + n);

    cnt = 0;

    for(i = 0; i < n; i++)
    {
        sum = ara[i] * 4;
        if(sum >= a && sum <= b)
            cnt++;
    }



    for(i = 0; i < n; i++){
        sum = ara[i]*3;
        for(j = 0; j < n; j++){
            if(i == j)
                continue;
            sum += ara[j];
        if(sum >= a && sum <= b)
            cnt++;
        }
    }

    for(i = 0; i < n; i++){
        sum = ara[i] * 2;
        for(j = i + 1; j < n; j++){
            sum += ara[j] * 2;
        if(sum >= a && sum <= b)
            cnt++;
        }
    }

    for(i = 0; i < n; i++){
        sum = ara[i];

        for(j = i + 1; j < n - 2;j++){
            sum += ara[j] + ara[j + 1] + ara[j + 2];
        if(sum >= a && sum <= b)
            cnt++;
        }
    }

    for(i = 0; i < n; i++){
        for(j = 0; j < n;j++){
            if(i == j)
                continue;
                for(k = 0; k < n; k++){
                    if(k == i || k == j)
                        continue;

                    sum = ara[i] * 2 + ara[j] + ara[k];
                       if(sum >= a && sum <= b)
                            cnt++;

                }
            }
        }

    printf("Case %lld: %lld", ++cs, cnt);
    }
    return 0;
}
