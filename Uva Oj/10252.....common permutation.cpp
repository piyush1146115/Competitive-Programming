#include<bits/stdc++.h>
using namespace std;

int main()
{
    int flag1[30],flag2[30], i, j, k, len1, len2;
    char a[1005], b[1005];

    while(gets(a)){

        gets(b);
        for(i = 0; i < 27; i++){
        flag1[i] = 0;
        flag2[i] = 0;
        }

        len1 = strlen(a);
        for(i = 0; i < len1; i++)
            flag1[a[i] - 'a']++;

        len2 = strlen(b);
        for(i = 0; i < len2; i++)
            flag2[b[i] - 'a']++;

        for(i = 0;i < 26; i++){
            if(flag1[i] > 0 && flag2[i] > 0){
                j = min(flag1[i], flag2[i]);

                for(k = 1; k <= j; k++)
                printf("%c",i + 97);
            }
        }

        printf("\n");
    }
    return 0;
}
