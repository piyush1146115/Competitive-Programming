#include<bits/stdc++.h>
using namespace std;

int coin[] = {5, 10, 20, 50, 100, 200};
int ara[10];
int dp1[7][505];
int dp2[7][505][505];

int change(int pos, int sum)
{
    if(sum == 0)
    return 0;

    if(pos == 6){
        return 999999;
    }
    if(sum < 0)
        return 999999;

    if(dp1[pos][sum]!= -1)
        return dp1[pos][sum];

    int ret = 999999;

    ret = min(ret, 1 + change(pos , sum - coin[pos]));
    ret = min(ret, change(pos + 1, sum));

    return dp1[pos][sum] = ret;
}


int make(int pos, int state, int sum)
{
    if(sum == 0)
        return 0;

    if(sum < 0){
        return change(0, abs(sum));
    }

    if(pos == 6){
        return 999999;
    }

    if(dp2[pos][state][sum] != -1)
        return dp2[pos][state][sum];

    int ret = 999999;

    if(state < ara[pos])
        ret = min( ret, 1 + make(pos, state + 1, sum - coin[pos]));


    ret = min(ret, make( pos + 1, 0, sum));



    return dp2[pos][state][sum] = ret;
}


int main()
{
 while(scanf("%d %d %d %d %d %d",&ara[0], &ara[1], &ara[2], &ara[3], &ara[4], &ara[5])){
    if(ara[0] == 0 && ara[1] == 0 && ara[2] == 0 && ara[3] == 0 && ara[4] == 0 && ara[5] == 0)
        break;

    memset(dp1, -1, sizeof(dp1));
    memset(dp2, -1, sizeof(dp2));
    double d;

    scanf("%lf", &d);
    d *= 100.0;


    int n = (int)d;
    if(n % 5 != 0)
        n++;

    int ans;

    ans =  make(0, 0, n);


   printf("%3d\n",ans);
 }
}
