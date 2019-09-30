#include<bits/stdc++.h>
using namespace std;
char str[10][5]= {
        { ' ' },
        { '.', ',', '?', '"' },
        { 'a', 'b', 'c' },
        { 'd', 'e', 'f' },
        { 'g', 'h', 'i' },
        { 'j', 'k', 'l' },
        { 'm', 'n', 'o' },
        { 'p', 'q', 'r', 's' },
        { 't', 'u', 'v' },
        { 'w', 'x', 'y', 'z' }
};
struct MSg{
int ind;
int frq;
};

struct MSg m[105];
int main()
{
    int test, l, i, j;

    scanf("%d", &test);

    while(test--){
        scanf("%d",&l);

        for(i = 0; i < l; i++){
            scanf("%d", &m[i].ind);
        }

         for(i = 0; i < l; i++){
            scanf("%d", &m[i].frq);
        }
        for(i = 0; i < l; i++){
            if(m[i].ind != 0){
                printf("%c", str[m[i].ind][m[i].frq - 1]);
            }
            else{
                for(j = 1; j <= m[i].frq; j++){
                    printf(" ");
                }
            }
        }
        printf("\n");
    }
    return 0;
}
