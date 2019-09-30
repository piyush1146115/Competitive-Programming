#include<bits/stdc++.h>
using namespace std;

int main()
{
        long long m, x, i, j, k;
        double per, val;

        while(scanf("%lld %lld", &m, &x) == 2){
            if(m == 0 && x == 0)
                break;
            if(x == 0 || x == 100)
                printf("Not found\n");
            else{
                bool flag = true;

                k = (m -1) * 100 / (100 - x);

                if((m -1) * 100 % (100 - x) == 0)
                    k--;

                if(k >= m)
                flag = false;

                if(flag)
                        printf("Not found\n");
                else
                printf("%lld\n",k);
            }
        }
}
