#include<bits/stdc++.h>
using namespace std;
#define MX 105
char grid[MX][MX];
int row, col;

int fx[] = {+0, -1, +0, +1};
int fy[] = {+1, +0, -1, +0};


bool valid(int x, int y)
{
    if(x < 0 || y < 0 || x >= row || y >= col ||grid[x][y] == '#')
        return false;

    return true;
}

int main()
{

    int i,j, k, l, m, n;
    int sx, sy, indx;

    string di;

    while(scanf("%d %d %d",&row, &col, &n) == 3){

        if(row == 0 && col == 0 && n == 0)
            break;

        for(i = 0; i < row; i++)
            scanf("%s",grid[i]);

            cin >> di;
            int flag = 0;


        for(i = 0; i < row; i++){
            for(j = 0; j < col ;j++){

                if(grid[i][j] == 'N'){
                    indx = 1;
                    sx = i;
                    sy = j;
                    flag = 1;
                    //cout << "ok" << " " << i << " " << j << endl;
                    break;
                }

                if(grid[i][j] == 'S'){
                    indx = 3;
                    sx = i;
                    sy = j;
                    flag = 1;
                    break;
                }

                if(grid[i][j] == 'L'){
                    indx = 0;
                    sx = i;
                    sy = j;
                    flag = 1;
                    break;
                }
                if(grid[i][j] == 'O'){
                    indx = 2;
                    sx = i;
                    sy = j;
                    flag = 1;
                    break;
                }
            }
           /* if(flag)
                break;*/
        }

        int co = 0;

        for(i = 0; i < n; i++){
            //cout << sx<< " " << sy << endl;
                //getchar();
                 //cout << sx<< " " << sy << " " << indx << " " << fx[indx] << " " << fy[indx] << endl;
            if(di[i] == 'F'){

                int tx  = sx + fx[indx];
                int  ty = sy +fy[indx];

                if(valid(tx, ty)){
                    sx = tx;
                    sy = ty;
                }

            if(grid[sx][sy] == '*'){
                co++;

                grid[sx][sy] = '.';
              }
            }
            else if(di[i] == 'E'){
                indx++;
                if(indx == 4)
                    indx = 0;
            }
            else if(di[i] == 'D'){
                indx--;
                if(indx == -1)
                    indx = 3;
            }
        }
        printf("%d\n",co);
    }
    return 0;
}
