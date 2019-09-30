#include<bits/stdc++.h>
using namespace std;

int main()
{
    int i, j, k, d, len;
    char num[110], ans[110];

    while(scanf("%d %s",&d, num) == 2){
        if(num[0] == '0' && d == 0)
            break;

        len = strlen(num);
         k = 0;
        for(i = 0; i < len; i++){
            if(num[i] != (d + 48) && num[i] != '0')
                ans[k++] = num[i];
        }
        ans[k] = '\0';
        if( k == 0)
            printf("0\n");
        else
            printf("%s\n",ans);
    }
    return 0;
}
