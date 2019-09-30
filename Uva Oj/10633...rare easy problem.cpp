#include<bits/stdc++.h>
using namespace std;
int main()
{
    unsigned long long p, q, n, m;
    int i, j, k;
    unsigned long long ara[500];

    while(scanf("%llu", &p), p){

        /*q = (p / 10) + p;
        k = 0;
        while(1){
            m = q/ 10;
            n = q - m;
            if(n > p)
                break;

            if(n == p)
              ara[k++] = q;

            q++;
        }

        for(i = 0; i < k; i++){
            printf("%llu", ara[i]);
            if(i != k -1)
                printf(" ");
        }
        printf("\n");
        */
        if(p % 9 == 0){
            q = (p / 9) + p;
            printf("%llu %llu\n",q -1, q);
        }
        else{
            q = (p / 9) + p;
            printf("%llu\n", q);
        }
    }

    return 0;
}
