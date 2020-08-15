#include<bits/stdc++.h>
using namespace std;

int main()
{
    char piece[200];
    int len, m, f, i, test;

    scanf("%d", &test);
    getchar();
    while(test--){
        gets(piece);
        len = strlen(piece);
        m = 0;
        f = 0;

        for(i = 0; i < len; i++){
            if(piece[i] == 'M'){
                m++;
            }
            if(piece[i] == 'F'){
                f++;
            }
        }

        if(m == f && m > 1){
            printf("LOOP\n");
        }
        else{
            printf("NO LOOP\n");
        }
    }

    return 0;
}
