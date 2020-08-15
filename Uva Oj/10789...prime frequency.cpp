#include<bits/stdc++.h>
using namespace std;
int ara[2500];
void sieve()
{
    int i, j, k;
    ara[1] = 1;
    ara[0] = 1;

    for(i = 4; i <= 2400; i += 2){
        ara[i] = 1;
    }

    for(i = 3; i <= 50; i++){
            if(ara[i] == 0){
        for(j = i * i; j <= 2400; j += (i * 2)){
            ara[j] = 1;
        }
        }
    }
}

int main()
{
    //freopen("input.txt", "r", stdin);
    sieve();
    int i, j, test, freq[150], cse = 0;
    char str[2500];

    scanf("%d", &test);
    getchar();
    while(test--){
        cse++;
        memset(freq, 0, sizeof(freq));

        gets(str);
        int len = strlen(str);

        for(i = 0; i < len; i++)
            freq[str[i]]++;

        int flag = 1;;
        printf("Case %d: ",cse);
        for(i = 48; i < 130; i++){
            if(ara[freq[i]] == 0){
                printf("%c",i);
                flag = 0;
            }
        }
        if(flag)
            printf("empty");

        printf("\n");
    }
    return 0;
}
