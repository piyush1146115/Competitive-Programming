#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 100000007

ll way[10005];
int n, k, marker;
int c[105];

ll cnt( )
{
    ll i, j, x, y;

    // We need n+1 rows as the table is consturcted in bottom up manner using
    // the base case 0 value case (n = 0)
    ll table[k+1][n];
    memset(table, 0, sizeof(table));
    // Fill the enteries for 0 value case (n = 0)
    for (i=0; i<n; i++)
        table[0][i] = 1;
    
    // Fill rest of the table enteries in bottom up manner
    
    for (i = 1; i <= k; i++)
    {
        for (j = 0; j < n; j++)
        {
            // Count of solutions including c[j]
            x = 0, y = 0;

            if(i >= c[j])
            x = table[i - c[j]][j];

            // Count of solutions excluding S[j]
            if(j >= 1)
            y =  table[i][j-1];

            // total count
            table[i][j] = (x + y) %100000007;
        }
    }
    return table[k][n-1] ;
}

int main()
{
    int test;

    scanf("%d", &test);

    for(int tc = 1; tc <= test; tc++){
        scanf("%d %d", &n, &k);

        for(int i = 0; i < n; i++)
            scanf("%d",&c[i]);

        ll res = cnt() ;
        printf("Case %d: %lld\n",tc,res);
    }
    return 0;
}
