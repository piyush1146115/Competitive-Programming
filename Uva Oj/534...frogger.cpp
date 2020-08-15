#include<bits/stdc++.h>
using namespace std;
#define inf 1e9
double mat[205][205];
struct point{
int x;
int y;
}p[205];
int main()
{
    int i, j, k, n ,casen = 0;

    while(cin >> n, n){

        for(i = 0; i < n; i++){
            scanf("%d %d",&p[i].x, &p[i].y);
        }
//printf("%lf\n",mat[0][1]);
        for(i = 0; i < n ; i++){
            for(j = i + 1; j < n; j++){
                mat[i][j] =mat[j][i] =  sqrt(((p[i].x - p[j].x) * (p[i].x - p[j].x)) + ((p[i].y - p[j].y) * (p[i].y - p[j].y)));
            }
        }
//printf("%lf\n",mat[1][2]);
        for(k = 0; k < n; k++){
            for(i = 0; i < n; i++){
                for(j = 0; j < n; j++){
                    mat[i][j] = min(mat[i][j], max(mat[i][k] , mat[k][j]));
                }
            }
        }
        printf("Scenario #%d\n",++casen);
            printf("Frog Distance = %0.3lf\n\n",mat[0][1]);
    }
    return 0;
}
/*
// @BEGIN_OF_SOURCE_CODE

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <cctype>
#include <stack>
#include <queue>
#include <list>
#include <vector>
#include <map>
#include <sstream>
#include <cmath>
#include <bitset>
#include <utility>
#include <set>
#define INT_MAX 2147483647
#define INT_MIN -2147483648
#define pi acos(-1.0)
#define N 1000000
#define LL long long
using namespace std;

double power (int b, int p)
{
    double ret = 1;

    for ( int i = 1; i <= p; i++ )
        ret *= b;

    return ret;
}

int main ()
{
    int stones;
    int cases = 0;

    while ( scanf ("%d", &stones) && stones ) {
        int x [200 + 10];
        int y [200 + 10];

        for ( int i = 0; i < stones; i++ ) scanf ("%d %d", &x [i], &y [i]);

        double d [200 + 10] [200 + 10];

        for ( int i = 0; i < stones; i++ ) {
            for ( int j = i + 1; j < stones; j++ )
                d [i] [j] = d [j] [i] = sqrt (power (x [i] - x [j], 2) + power (y [i] - y [j], 2));
        }

        for ( int k = 0; k < stones; k++ ) {
            for ( int i = 0; i < stones; i++ ) {
                for ( int j = 0; j < stones; j++ )
                    d [i] [j] = min (d [i] [j], max (d [i] [k], d [k] [j]));
            }
        }

        printf ("Scenario #%d\n", ++cases);
        printf ("Frog Distance = %.3lf\n\n", d [0] [1]);

    }

    return 0;
}
*/
