#include<bits/stdc++.h>
using namespace std;
int main()
{
    int mat[6][6], r, c, i, j;

    for(i = 1; i <= 5; i++){
        for(j = 1; j <= 5; j++){
            scanf("%d", &mat[i][j]);
            if(mat[i][j] == 1)
            {
                r = i;
                c = j;
            }
        }
    }

    int dis = fabs(r - 3) + fabs(c - 3);

    cout << dis << endl;

    return 0;
}
