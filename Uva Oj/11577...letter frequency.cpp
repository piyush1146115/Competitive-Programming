#include<bits/stdc++.h>
using namespace std;

int main()
{
    char str[500];
    int n , i, j, k, mx, len, ara[27];

    scanf("%d",&n);
    getchar();

    for(k = 0; k < n; k++){
        gets(str);
        mx = 0;

        for(i = 0; i < 26; i++)
            ara[i] = 0;

        len = strlen(str);

        for(i = 0; i < len; i++){
            if(str[i] >= 'a' && str[i] <= 'z'){
                j = str[i] - 'a';
                ara[j]++;
            }
            else if(str[i] >= 'A' && str[i] <= 'Z'){
                j = str[i] - 'A';
                ara[j]++;
            }
        }

        for(i = 0; i < 26; i++){
            mx = max(ara[i], mx);
        }

        for(i = 0; i < 26; i++){
            if(mx == ara[i]){
                printf("%c",i + 97);
            }
        }
        printf("\n");
    }

    return 0;
}
