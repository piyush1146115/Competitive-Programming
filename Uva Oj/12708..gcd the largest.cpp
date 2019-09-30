#include<stdio.h>
int main(){
    unsigned long long n,m;
    scanf("%llu", &n);
    while(n--){
        scanf("%llu", &m);
        printf("%llu\n", m>>1);
    }
    return 0;
}
