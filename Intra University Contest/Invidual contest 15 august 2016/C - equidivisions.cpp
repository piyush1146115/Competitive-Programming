#include<bits/stdc++.h>
using namespace std;
int n, m, cnt;
int mat[105][105];

void dfs(int i,int  j,int  k)
{
    if(i < 0 || j < 0 || i == n || j == n)
        return;
    if(mat[i][j] != k)
        return;

    if(mat[i][j] == k)
        cnt++;

        mat[i][j] = 0;
        dfs(i + 1, j, k);
        dfs(i -1 , j, k);
        dfs(i , j - 1, k);
        dfs(i, j + 1, k);
}

int main()
{
    //freopen("input.txt", "r", stdin);
    int i, j, k, x, y;
    string s;

    while(scanf("%d", &n) == 1 && n != 0){

            memset(mat, 0, sizeof(mat));
            getchar();

        for(i = 0; i < n - 1; i++){
                getline(cin , s);
                stringstream ss(s);
                while(ss >> x >> y){
                    mat[x -1][y - 1] = i + 1;
                }
    }

    for(i = 0; i < n; i++ ){
        for(j = 0; j < n; j++){
            if(mat[i][j] == 0){
                mat[i][j] = n;
            }
        }
    }

    /*for(i = 0; i < n; i++ ){
        for(j = 0; j < n; j++){
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }
*/

    int flag = 1;
    for(i = 0; i < n; i++){
        for(j = 0; j < n; j++){
            if(mat[i][j] != 0){
                    cnt = 0;
                k = mat[i][j];
                dfs(i, j, k);
                //cout << mat[i][j] << " " << cnt << endl;
                if(cnt != n)
                flag = 0;
            }
        }
        if(flag == 0)
            break;
    }
    if(flag){
        printf("good\n");
    }
    else{
        printf("wrong\n");
    }
    }
    return 0;
}
