#include<bits/stdc++.h>
using namespace std;
int main()
{
    int dir[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    int row, col, i, j, k, r, c, cont = 0;
    char grid[20][20];

    cin >> row >> col;

    for(i = 0; i < row; i++)
        scanf("%s", grid[i]);

    for(i = 0; i < row; i++){
        for(j = 0; j < col; j++){
            if(grid[i][j] == 'W'){
                for(k = 0; k < 4;k++ ){
                    r = i + dir[k][0];
                    c = j + dir[k][1];
                    //printf("%d %d\n",r, c);
                    if(r >= 0 && c >= 0 && r < row && c < col){
                        if(grid[r][c] == 'P'){
                            cont++;
                            break;
                        }
                    }
                }
            }
        }
    }
    cout << cont << endl;

    return 0;
}
