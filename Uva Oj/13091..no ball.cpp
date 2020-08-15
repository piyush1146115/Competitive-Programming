#include<bits/stdc++.h>
using namespace std;
int main()
{
    //freopen("input.txt", "r", stdin);

    char str[6][10], ch;
    int i, j, k, test, p1, p2;

    cin >> test;

    for(i = 1; i <= test; i++){

        for(j = 0; j < 5; j++)
            scanf("%s",str[j]);

        for(j = 0; j < 5; j++){
            for(k = 0; k < 5; k++){
                if(str[j][k] == '|'){
                    p1 = k;
                }
                if(str[j][k] == '<' || str[j][k] == '>'){
                    p2 = k;
                    ch = str[j][k];
                   // printf("%c\n",ch);
                }
            }
        }
        if( (p2 > p1 && ch == '>') || (p2 < p1 && ch == '<'))
            printf("Case %d: No Ball\n", i);
        else
            printf("Case %d: Thik Ball\n", i);
    }
    return 0;
}
