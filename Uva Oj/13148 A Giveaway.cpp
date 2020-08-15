#include<bits/stdc++.h>
using namespace std;
int main()
{
  long long  int ara[] = {1, 64, 729, 4096, 15625, 46656, 117649, 262144, 531441,
1000000, 1771561, 2985984, 4826809, 7529536, 11390625, 16777216, 24137569, 34012224,
47045881, 64000000 , 85766121};

    long long n;
    while(scanf("%lld", &n) == 1){
            if(n == 0)
            break;
    int flag = 1;

        for(int i = 0; i < 21; i++){
            if(ara[i] == n){
                printf("Special\n");
                flag = 0;
                break;
            }

        }
        if(flag)
            printf("Ordinary\n");
    }

return 0;
}
