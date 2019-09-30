#include<stdio.h>
#include<string.h>
int main()
{
    char str[50];
    int a, b ,test, n, pos, num, i, l;
    int ara[105];

    scanf("%d",&test);
    while(test--){
            pos = 0;
        scanf("%d",&n);
        getchar();
        for(a = 0; a < n; a++){
            gets(str);

           if(str[0] == 'L'){
            pos = pos - 1;
            ara[a] = -1;
        }
        else if(str[0] == 'R'){
            pos++;
            ara[a] = 1;

        }
        else if(str[0] == 'S'){
            l = strlen(str);
            num = 0;
            for(b = 8; b < l; b++){
                if(str[b] >= '0' && str[b] <= '9'){
                    i = str[b] - '0';
                    num = i + num*10;
                }
            }
            ara[a] = ara[num - 1];
            pos = pos + ara[a];
        }

        }
        printf("%d\n",pos);
    }
    return 0;
}
