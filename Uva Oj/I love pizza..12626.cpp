#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;



int main()
{
    int a, b, c, i, j, k, l, n;
    char str[650];
    int ara[30], ara2[6];


    scanf("%d",&n);
    getchar();

    for(a = 1; a <= n; a++){
        for(c = 0; c < 30; c++)
            ara[c] = 0;

        for(c = 0; c < 6; c++)
            ara2[c] = 0;

        gets(str);
        l = strlen(str);

        for(i = 0; i < l; i++){
            b = str[i] - 64;
            ara[b]++;
        }
        ara2[0] = ara[1]/3;
        ara2[1] = ara[7];
        ara2[2] = ara[9];
        ara2[3] = ara[13];
        ara2[4] = ara[18] / 2;
        ara2[5] = ara[20];

        sort(ara2, ara2 + 6);

        printf("%d\n",ara2[0]);
    }
    return 0;
}
