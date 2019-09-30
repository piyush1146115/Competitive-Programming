#include<bits/stdc++.h>
using namespace std;
int main()
{
    char grid[160][160];
    int i, j, k, pos = 0, c = 0, n, m, mov = 0;

    cin >> n >> m;

    for(i = 0; i < n; i++)
        scanf("%s", grid[i]);

    for(i = 0; i < n; i++){
        if(i % 2 == 0){
            for(j = 0; j < m;j++){
                if(grid[i][j] == 'W'){
                    c = j;
                }
            }

            if(c > pos){
                mov += (c - pos);
                pos = c;
            }
            k = i + 1;

            if(k < n){
                for(j = m - 1; j >= 0; j--){
                    if(grid[k][j] == 'W'){
                        c = j;
                        break;
                    }
                }
                if(c > pos){
                    mov += (c - pos);
                    pos = c;
                }
            }
        }
        else{
            for(j = m - 1; j >= 0; j--){
                if(grid[i][j] == 'W'){
                    c = j;
                }
            }
            if(c < pos){
                mov += (pos - c);
                pos = c;
            }
            k = i + 1;
            if(k < n){
                for(j = 0; j < m; j++){
                    if(grid[k][j] == 'W'){
                        c = j;
                        break;
                    }
                }
                if(c < pos){
                    mov += (pos - c);
                    pos = c;
                }
            }
        }
    }

    int f = 0;
    for(i = n - 1; i >= 0; i--){
        for(j = 0; j < m; j++){
            if(grid[i][j] == 'W'){
                f = 1;
                break;
            }
        }
        if(f){
            break;
        }
    }

    if(i > 0)
    mov += i;

    cout << mov << endl;
}
