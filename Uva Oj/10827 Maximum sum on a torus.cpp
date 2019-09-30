#include<bits/stdc++.h>
using namespace std;
int mat[155][155], sum[155][155];

int main()
{

    int n, m;

    int test;

    scanf("%d", &test);

    while(test--)
    {

        scanf("%d",&n);
        memset(sum , 0 , sizeof(sum));

        for(int i =1; i <= n; i++)
        {
            for(int j = 1; j <= n; j++)
            {
                scanf("%d",&mat[i][j]);
            }
        }


        for(int i = 1; i <= n; i++)
        {
            for(int j = 1; j <= n; j++)
            {
                mat[i][j + n] = mat[i][j];
            }
        }
        for(int i = 1; i <= 2 * n; i++)
        {
            for(int j = 1; j <= n; j++)
            {
                sum[j][i] = sum[j - 1][i] + mat[j][i];
            }
        }


//        for(int i = 1; i <= n; i ++)
//        {
//            for(int j = 1; j <= 2 *n; j++)
//                cout << sum[i][j] << " ";
//
//            cout << endl;
//        }


        int mxx = 0;

        for(int i = 1; i <= n; i++)
        {
            for(int j = i; j <= n; j++)
            {
                for(int k = 0; k < n; k++)
                {
                    int s = 0;
                    for(int x = 1 + k ; x <= n + k; x++)
                    {
                        s += (sum[j][x] - sum[i - 1][x]);
                        if( s < 0)
                            s = 0;

                        mxx = max(s, mxx);
                    }
                }
            }
        }

//
//
//        for(int i = 1; i <= n; i++)
//        {
//            for(int j = 1; j <= n; j++)
//            {
//                mat[i + n][j] = mat[i][j];
//            }
//        }
//
//        memset(sum, 0, sizeof(sum));
//
//        for(int i = 1; i <= n; i++)
//        {
//            for(int j = 1; j <= 2 * n; j++)
//            {
//                sum[j][i] = sum[j - 1][i] + mat[j][i];
//            }
//        }
//
//        int k;
//
//        for(int i = 1; i <= 2 * n; i++)
//        {
//            if(i <= n)
//                k = (i + n - 1);
//            else
//                k = 2 * n;
//
//            for(int j = i; j <= k; j++)
//            {
//                int s = 0;
//                for(int x = 1 ; x <= n; x++)
//                {
//                    s += (sum[j][x] - sum[i - 1][x]);
//                    if( s < 0)
//                        s = 0;
//                    mxx = max(s, mxx);
//                }
//            }
//        }
//
//        if(mxx == 0)
//        {
//            mxx = -500;
//
//            for(int i = 1; i <= n; i++)
//            {
//                for(int j = 1; j <= n; j++)
//                {
//                    mxx = max(mat[i][j], mxx);
//                }
//            }
//        }
       printf("%d\n",mxx);
    }
}
