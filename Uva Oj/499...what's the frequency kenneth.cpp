#include<bits/stdc++.h>
using namespace std;
int main()
{
   // freopen("input.txt", "r",stdin);
    int ara[150], i, len, mx;
    char str[5000];

    while(gets(str)){
        len = strlen(str);
        memset(ara, 0, sizeof(ara));

        for(i = 0 ; i < len; i++){
            if(isalpha(str[i]))
            ara[str[i]]++;
        }

        mx = -100;
        for(i = 40; i < 130; i++){
            if(ara[i] > mx)
                mx = ara[i];
        }

        for(i = 48; i < 130; i++){
            if(ara[i] == mx)
                printf("%c",i);
        }
        printf(" %d\n",mx);
    }
    return 0;
}
