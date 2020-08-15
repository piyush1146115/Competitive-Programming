#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
 int test;

 scanf("%d", &test);

 while(test--){
    int n;
    scanf("%d", &n);

    int flag = 1;
    int ans = 0;

    for(int i = 0; i < n; i++){
        int k;
        scanf("%d", &k);

        if(k != 1)
            flag = 0;
        ans ^= k;
    }

    if(flag){
        if(n % 2 == 0){
            printf("John\n");
        }
        else{
            printf("Brother\n");
        }
    }
    else{
        if(!ans){
            printf("Brother\n");
        }
        else{
            printf("John\n");
        }
    }
 }
}
