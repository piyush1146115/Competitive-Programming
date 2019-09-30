#include<bits/stdc++.h>
using namespace std;
struct slogan
{
    char sl1[105];
    char sl2[105];
};

struct slogan s[25];
int main()
{
    int n, m, i, j;
    char str[105];

    scanf("%d",&n);
    getchar();
    for(i = 0; i < n; i++){
        gets(s[i].sl1);
        gets(s[i].sl2);
    }

    scanf("%d", &m);
    getchar();
    for(i = 0; i < m; i++){
        gets(str);
       // getchar();
        for(j = 0; j < n; j++){
            if(strcmp(str, s[j].sl1) == 0){
                printf("%s\n", s[j].sl2);
                break;
            }
        }
    }
    return 0;
}
