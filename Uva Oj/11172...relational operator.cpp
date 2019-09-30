#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long a, b, test;

    scanf("%lld",&test);

    while(test--){
        scanf("%lld %lld",&a, &b);

        if(a > b){
            printf(">\n");
        }
        else if(a < b){
            printf("<\n");
        }
        else{
            printf("=\n");
        }
    }
    return 0;
}
