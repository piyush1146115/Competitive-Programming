#include<bits/stdc++.h>
using namespace std;
int main()
{
    vector<long long> v;
    long long m, n, i;

    while(scanf("%lld %lld", &n, &m) == 2){

            if(n < 2 || m < 2)
            printf("Boring!\n");
        else{
        while(n > 1){
            if(n %m != 0)
                break;
            v.push_back(n);
            n = n / m;
        }

        if(n == 1){
            for(i = 0; i < v.size(); i++)
                printf("%lld ",v[i]);

            printf("1\n");
        }
        else
            printf("Boring!\n");
        }
        v.clear();
    }

    return 0;
}
