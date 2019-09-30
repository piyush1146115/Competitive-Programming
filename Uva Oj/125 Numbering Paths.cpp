#include<bits/stdc++.h>
using namespace std;
#define mxx 35

int mat[mxx][mxx];



int main()
{
    int n, tc = 0;

    while(scanf("%d",&n) == 1)
    {
        int N = 0;
        memset(mat, 0, sizeof(mat));

        for(int i = 0; i < n; i++)
        {
            int u, v;
            scanf("%d %d",&u, &v);
            mat[u][v] = 1;
            //g[u].push_back(v);
            N = max(N, max(u, v));
        }


        for(int k = 0; k <= N; k++)
        {
            for(int i = 0; i <= N; i++)
            {
                for(int j = 0; j <= N; j++)
                {
                    if(mat[i][k] && mat[k][j])
                        mat[i][j] += (mat[i][k] * mat[k][j]);
                }
            }
        }

        for(int k = 0; k <= N; k++)
        {
            if(mat[k][k])
            {
                for(int i = 0; i <= N; i++)
                {
                    for(int j = 0; j <= N; j++)
                    {
                        if(mat[i][k]  && mat[k][j])
                            mat[i][j] = -1;
                    }
                }
            }
        }


        printf("matrix for city %d\n",tc++);

        for(int i = 0; i <= N; i++)
        {
            for(int j = 0; j <= N; j++)
            {
                if(j != 0)
                    printf(" ");
                printf("%d",mat[i][j]);
            }
            printf("\n");
        }
    }
}
