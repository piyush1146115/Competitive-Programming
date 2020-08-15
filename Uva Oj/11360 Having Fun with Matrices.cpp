#include<bits/stdc++.h>
using namespace std;
int n;
char mat[15][15], temp[15][15];
void transpose()
{
    int i, j;

    for(i = 0; i < n; i++){
        for(j = 0; j < n; j++){
            temp[j][i] = mat[i][j];
        }
    }

    for(i = 0; i < n; i++){
        for(j = 0; j < n; j++){
            mat[i][j] = temp[i][j];
        }
    }
}
void inc()
{
    int i, j;
    for(i = 0; i < n; i++){
        for(j = 0; j < n; j++){
            mat [i][j] += 1;
            if(mat[i][j] == 58)
                mat[i][j] = 48;
        }
    }
}

void dec()
{
    int i, j;
    for(i = 0; i < n; i++){
        for(j = 0; j < n; j++){
            mat [i][j] -= 1;
            if(mat[i][j] == 47)
                mat[i][j] = 57;
        }
    }
}

void r(int i, int j)
{
    for(int k = 0; k < n; k++){
        swap(mat[i][k], mat[j][k]);
    }
}

void c(int i, int j)
{
    for(int k = 0; k < n; k++){
        swap(mat[k][i], mat[k][j]);
    }
}
int main()
{
   // freopen("input.txt", "r", stdin);
    int i, j, k, cs = 0, test, x, y;
    string s;
    scanf("%d", &test);

    while(test--){
        scanf("%d", &n);

        for(i = 0; i < n; i++)
            scanf("%s",mat[i]);

         scanf("%d" , &k);
         //getchar();

         while(k--){
           // getline(cin, s);
           cin >> s;
            if(s == "transpose"){
                transpose();
            }
            else if(s == "inc"){
                inc();
            }
            else if(s == "dec"){
                dec();
            }
            else if(s == "row"){
                scanf("%d %d", &x, &y);
                r(x - 1, y - 1);
            }
            else if(s == "col"){
                scanf("%d %d", &x, &y);
                c(x - 1, y - 1);
            }
         }

         printf("Case #%d\n", ++cs);
        for(i = 0; i < n; i++){
            for(j = 0; j < n; j++){
                printf("%c", mat[i][j]);
            }
            printf("\n");
        }
        printf("\n");
    }
}
