#include<bits/stdc++.h>
using namespace std;
int main()
{
    char deco[250];
    int i, j, k, len, test, cse = 0;

    scanf("%d", &test);

    while(test--){
            cse++;
        scanf("%s", deco);

        len = strlen(deco);
        printf("Case %d: ",cse);
        for(i = 0; i < len; i++){
            if(!isalpha(deco[i])){
                j = 0;
                int l = i - 1;
                while(!isalpha(deco[i]) && i < len){
                    j = (deco[i] - '0') + j * 10;
                     // printf("\n%d\n", j);
                    i++;
                }
                i--;

                for(k = 1; k < j; k++)
                    printf("%c",deco[l]);
            }
            else{
                printf("%c",deco[i]);
            }
        }
        printf("\n");
    }
    return 0;
}
