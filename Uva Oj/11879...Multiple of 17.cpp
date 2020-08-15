#include<bits/stdc++.h>
using namespace std;

int main()
{
    char n[110];
    int len, i, j, num, rem;

    while(gets(n)){
        if(n[0] == '0'){
            break;
        }
        len = strlen(n);
        rem = 0;
        for(i = 0; i < len; i++){
            rem = (n[i] - 48 + rem * 10) % 17;
        }
        if(rem == 0){
            printf("1\n");
        }
        else{
            printf("0\n");
        }
    }
    return 0;
}
