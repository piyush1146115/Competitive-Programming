#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>

using namespace std;
int main()
{
    char str[10];
    int a, b, c, i, j, k, l, n, num, num2, dif;

    scanf("%d",&n);
    getchar();

    for(a = 1; a <= n; a++){
        gets(str);
        num = 0;

        for(b = 4; b < 8; b++){
            c = str[b] - '0';
            num = c + (num * 10);
        }

        num2 = 0;
        k = 0;

        for(i = 2; i >= 0;i--){
            j = str[i] - 'A';
            l = j * pow(26,k);
            num2 += l;
            k++;
        }
        dif = fabs(num2 - num);
        if(dif > 100){
            printf("not nice\n");
        }
        else{
            printf("nice\n");
        }
    }
    return 0;
}
