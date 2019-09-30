#include<bits/stdc++.h>
using namespace std;
#define ll long long
int mat[5][5];
int main()
{
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
            scanf("%d", &mat[i][j]);
        }
    }

    int flag = 1;

    if(mat[0][3] == 1){
        if(mat[0][0] == 1 || mat[0][1] == 1 || mat[0][2] == 1 || mat[1][0] == 1|| mat[3][2] == 1 || mat[2][1] == 1){
            flag = 0;
        }
    }

    if(mat[1][3] == 1){
        if(mat[1][0] == 1 || mat[1][1] == 1 || mat[1][2] == 1 || mat[2][0] == 1|| mat[0][2] == 1 || mat[3][1] == 1){
            flag = 0;
        }
    }

    if(mat[2][3] == 1){
        if(mat[2][0] == 1 || mat[2][1] == 1 || mat[2][2] == 1 || mat[3][0] == 1|| mat[1][2] == 1 || mat[0][1] == 1){
            flag = 0;
        }
    }

    if(mat[3][3] == 1){
        if(mat[3][0] == 1 || mat[3][1] == 1 || mat[3][2] == 1 || mat[0][0] == 1|| mat[2][2] == 1 || mat[1][1] == 1){
            flag = 0;
        }
    }

    if(!flag)
        printf("YES\n");
    else
        printf("NO\n");
}
