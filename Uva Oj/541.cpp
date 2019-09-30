#include<bits/stdc++.h>
using namespace std;
int main()
{
    //freopen("input.txt", "r", stdin);

    int mat[102][102], i, j, k, n, sum;
    vector<int> row, col;

    while(scanf("%d", &n) == 1 && n != 0){

        for(i = 0; i < n; i++){
            for(j = 0; j < n; j++){
                scanf("%d",&mat[i][j]);
            }
        }

                for(i = 0; i < n; i++){
                        sum = 0;
            for(j = 0; j < n; j++){
                sum += mat[i][j];
            }
            if(sum % 2 != 0)
                row.push_back(i + 1);
        }

                for(i = 0; i < n; i++){
                        sum = 0;
            for(j = 0; j < n; j++){
                sum += mat[j][i];
            }
            if(sum % 2 != 0)
                col.push_back(i + 1);
        }
        if(row.size() == 0 && col.size() == 0){
            printf("OK\n");
        }
        else if(row.size() == 1 && col.size() == 1){
            printf("Change bit (%d,%d)\n",row[0], col[0]);
        }
        else{
            printf("Corrupt\n");
        }
    row.clear();
    col.clear();
    }
    return 0;
}
