#include<bits/stdc++.h>
using namespace std;
char key[22][22];
char excuse[22][70];

int main()
{
    int i, j, k, e, len;
    int a, b, c, d;

    while(scanf("%d %d",&k, &e) == 2){
        for(i = 0; i < k; i++){
            scanf("%s",key[i]);
        }
        getchar();

        for(i = 0; i < k; i++){
            gets(excuse[i]);
        }

        for(i = 0; i < k; i++){
            len = strlen(excuse[i]);
            j = 0;

            while(j < len){
                for(a = 0; a < k; a++){
                    if(key[a][0] == excuse[i][j] || (key[a][0] == excuse[i][j] - 32)){
                        c = 1;
                        j++;
                        while(key[a][c] == excuse[i][j] || (key[a][c] == excuse[i][j] - 32) ){
                            j++;
                            c++;


                            }
                        }
                    }
                }
            }
        }

}
