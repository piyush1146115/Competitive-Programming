#include<bits/stdc++.h>
using namespace std;
int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "wt", stdout);

    char inp[500];
    int i, j, num, k;

    while(gets(inp)){
        int len = strlen(inp);
        for(i = 0; i < len; i++){
                num = 0;
            while(inp[i] >= '0' && inp[i] <= '9'){
                num += inp[i] - '0';
                i++;
            }
            if(inp[i] == '!')
                    printf("\n");
            if(num == 0 && inp[i] == 'b')
                printf(" ");

            for(j = 0; j < num; j++){
                if(inp[i] == 'b')
                    printf(" ");
                else
                    printf("%c",inp[i]);
            }
        }
        printf("\n");
    }
    return 0;
}
