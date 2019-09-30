#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n, i, m = 0, c = 0, a, b;

    scanf("%d",&n);

    for(i = 0; i < n; i++){
        scanf("%d %d",&a, &b);
        if(a == b){
            m++;
            c++;
        }
        else if(a > b){
            m++;
        }
        else{
            c++;
        }
    }
    if(m == c){
        printf("Friendship is magic!^^\n");
    }
    else if(m > c){
        printf("Mishka\n");
    }
    else{
        printf("Chris\n");
    }
    return 0;
}
