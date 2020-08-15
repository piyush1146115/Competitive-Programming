#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long int digit[15], n, i, res, k, a, b, j,  dif, f;

    while(scanf("%lld",&n) == 1)
    {
        memset(digit, 0, sizeof(digit));

        while(n != 0)
        {
            digit[n % 10]++;
            n /= 10;
        }
        b = 0;
        for( i = 9; i >= 0; i--)
        {
            if(digit[i] > 0)
            {
                f = digit[i];
                while(f--)
                    b = i + b * 10;
            }
        }
        a = 0;
        int flag = 0;
        for(i = 1; i <= 9; i++)
        {
            if(digit[i] > 0)
            {
                a = i + a * 10;
                if(flag == 0)
                {
                    f = digit[0];
                    while(f--)
                    {
                        a = 0 + a * 10;
                    }
                    flag = 1;
                }
                f = digit[i] - 1;
                while(f--)
                {
                    a = i + a*10;
                }
            }
        }

        dif = b - a;
        res = dif / 9;

        printf("%lld - %lld = %lld = 9 * %lld\n",b, a, dif, res);
    }
    return 0;
}
