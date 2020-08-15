#include<bits/stdc++.h>
using namespace std;
#define M 105
int main()
{
    //freopen("input.txt", "rt", stdin);

    char st1[M], st2[M], br1[M], br2[M], st3[M], st4[M];
    int len1, len2, lenb1, lenb2, len3, len4, test, i, j, k;

    scanf("%d", &test);
    getchar();

    while(test--){
        gets(st1);
        gets(st2);

        len1 = strlen(st1);

        for(i = 0; i < len1; i++){
            if(st1[i] == '<'){
                k = 0;
                i++;
                while(st1[i] != '>'){
                    br1[k++] = st1[i];
                    i++;
                }
                lenb1 = k;

                k = 0;
                i++;
                   while(st1[i] != '<'){
                    st3[k++] = st1[i];
                    i++;
                }
                len3 = k;

                k = 0;
                i++;
                   while(st1[i] != '>'){
                    br2[k++] = st1[i];
                    i++;
                }
                lenb2 = k;

                k = 0;
                i++;

                while(i < len1){
                    st4[k++] = st1[i];
                    i++;
                }
                len4 = k;
            }
        }
        len2 = strlen(st2);

            for(i = 0; i < len1; i++){
            if(st1[i] == '<' || st1[i] == '>'){
                continue;
            }
            else
                printf("%c", st1[i]);
        }

        printf("\n");
        i = 0;
        while(st2[i] != '.'){
            printf("%c",st2[i]);
            i++;
        }

        for( i = 0; i < lenb2; i++)
        printf("%c",br2[i]);

        for( i = 0; i < len3; i++)
        printf("%c",st3[i]);

        for( i = 0; i < lenb1; i++)
        printf("%c",br1[i]);

        for( i = 0; i < len4; i++)
        printf("%c",st4[i]);

        printf("\n");
    }
    return 0;
}
