#include<bits/stdc++.h>
using namespace std;

int main()
{
    int a, b, c, d, l, i, div, sum;

    while(scanf("%d %d %d %d %d", &a, &b, &c, &d, &l) == 5 && ( a != 0 || b != 0 || c != 0 || d != 0 || l != 0)){
        div = 0;
        for(i = 0; i <= l; i++){
            sum = a * (i * i) + b * i + c;
            if(sum % d == 0){
                div++;
            }
        }
        printf("%d\n",div );
    }
    return 0;
}
