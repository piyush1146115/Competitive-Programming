#include<bits/stdc++.h>
using namespace std;
int main()
{
    int occur[260], i, n, cse = 0;
    char word[35];

    while(scanf("%d", &n) == 1){
        cse++;
        int cont = 0;
       // getchar();
        while(n--){
            memset(occur, 0, sizeof(occur));
            scanf("%s",word);
            int len = strlen(word);
            for(i = 0; i < len; i++)
                occur[word[i]]++;

            int c, flag = 1, j;

            for(j = 1; j <= 20; j++){
                c = 0;
                for(i = 65; i < 124; i++){
                    if(j == occur[i])
                        c++;
                    if(c == 2){
                        flag = 0;
                        break;
                    }
                }
                if(flag == 0)
                    break;
            }
            if(flag == 1&& len > 1)
            cont++;
        }
        printf("Case %d: %d\n",cse, cont);
    }
    return 0;
}
