#include<bits/stdc++.h>
using namespace std;
long long int com[25][25], d[25];

void nCr()
{
    int i, j;

    for(i = 0; i <= 22; i++){
        com[i][0] =  com[i][i] =  1;
        com[i][1] = i;
    }

    for(i = 1; i <= 22; i++){
        for(j = 1; j < i; j++){
            com[i][j] = com[i - 1][ j] + com[i - 1][j - 1];
        }
    }
}

void der()
{
    int i;
d[0] = 1 ;
d[2] = 1;

for(i = 3; i <= 22; i++)
    d[i] = (i - 1) * (d[i - 1] + d[i - 2]);

}

int main()
{
    nCr();
    der();
    int n, m, i, j;

    long long ans;
    while(scanf("%d %d", &n, &m) == 2){
        ans = 0;
        for(i = 0;i <= m; i++){
            ans += com[n][i] * d[n - i];
            //cout << com[n][i] << " " << d[i] << endl;
        }


        printf("%lld\n",ans);
    }
    return 0;
}
