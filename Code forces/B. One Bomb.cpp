#include<bits/stdc++.h>
using namespace std;
char str[1005][1005];
int r[1005], c[1005];

int main()
{
    int row, col, i, j, k, c1,c2, total;

    cin >>row >>col;

    for(i = 0; i < row; i++)
        cin >> str[i];

    total = 0;

    for(i = 0; i < row; i++){
        for(j = 0; j < col; j++){
            if(str[i][j] == '*'){
             total++;
            }
        }
    }

    int flag = 0;

    for(i = 0; i < row; i++){
    for(j = 0; j < col; j++){
        if(str[i][j] == '*'){
         r[i]++;
        }
    }
    }

    //cout << r[0] << endl;
    for(i = 0; i < col; i++){
        for(j = 0 ; j < row; j++){
            if(str[j][i] == '*'){
                c[i]++;
            }
        }
    }

    for(i = 0; i < row; i++){
        for(j = 0; j < col ;j++){
            if(str[i][j] == '*')
            {
                if(r[i] + c[j] == total + 1){
                printf("YES\n%d %d\n",i + 1, j+ 1);
                flag =  1;
                }
            }
            else{
                if(r[i] + c[j] == total){
                printf("YES\n%d %d\n",i + 1, j+ 1);
                flag =  1;
                }
            }
            if(flag)
            break;
        }
        if(flag)
            break;
    }

    if(flag == 0)
        printf("NO\n");

}
/**
10 10
.........*
.........*
........**
.........*
.........*
.........*
.........*
.........*
.........*
.........*

*/
