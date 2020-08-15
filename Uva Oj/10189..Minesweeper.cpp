#include<bits/stdc++.h>
using namespace std;
int r, c;
char input[105][105], output[105][105];
void func(int i, int j)
{
    if(i >= 0 && j >= 0 && i < r && j < c){
        if(input[i][j] != '*'){
            output[i][j]++;
        }
    }
}
int main()
{
   // freopen("input.txt", "rt", stdin);
    //freopen("output.txt", "wt", stdout);

    int i, j, k, cont = 0;

    while(scanf("%d %d", &r, &c) == 2){

        if(r == 0 && c == 0)
        break;

        if(cont > 0)
            printf("\n");

        cont++;
        for(i = 0; i < r; i++)
            scanf("%s", input[i]);

        for(i = 0; i < r; i++){
            for(j = 0; j < c; j++){
                output[i][j] = 48;
            }
        }

        for(i = 0; i < r; i++){
            for(j = 0; j < c; j++){
                if(input[i][j] == '*'){
                    output[i][j] = '*';
                    func(i, j+ 1);
                    func(i, j -1);
                    func(i - 1, j);
                    func(i + 1, j);
                    func(i - 1, j + 1);
                    func(i - 1, j - 1);
                    func(i + 1, j + 1);
                    func(i + 1, j - 1);
                }
            }
        }
        printf("Field #%d:\n",cont);

        for(i = 0; i < r; i++){
            for(j = 0; j < c; j++){
                printf("%c", output[i][j]);
            }
            printf("\n");
        }

    }
    return 0;
}
