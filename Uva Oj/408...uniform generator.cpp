#include<bits/stdc++.h>
using namespace std;
int gcd(int a, int b){
    if(b == 0)
        return a;
    else
        return gcd(b, a %b);
}
int main()
{
    int a, b;
    while(scanf("%d %d", &a, &b) == 2){
        int g = gcd(a, b);
         printf("%10d%10d",a , b);
        if(g == 1){
           printf("    Good Choice\n\n");
        }
        else{
            printf("    Bad Choice\n\n");
        }
    }
    return 0;
}
