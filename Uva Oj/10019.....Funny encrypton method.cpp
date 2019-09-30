#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n, test, cb, chex, m, i, j, k;

    scanf("%d", &test);

    while(test--){
        scanf("%d", &n);
        m = n;

        cb = 0;
        while(m != 0){
            i = m % 2;
            m = m /2;
            if(i == 1){
                cb++;
            }
        }

        chex = 0;

        while(n != 0){
            k = n % 10;
            while(k != 0){
                j = k % 2;
                k = k/ 2;
                if(j == 1)
                    chex++;
            }
            n = n / 10;
        }

        printf("%d %d\n",cb, chex);
    }
    return 0;
}
