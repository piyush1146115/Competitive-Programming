
#include<bits/stdc++.h>
using namespace std;

double DP[505][505][3];

double fun(int R, int B, int state)
{
  //  cout << R << " " << B << " " << state << endl;
  //  getchar();

    if(B > 0 && R <= 0){
        return 1.000000000;
    }
//    if(state == 1 && B <= 0){
//        return 0.0000000000;
//    }
    if(R > 0 && B <= 0){
        return 0.0000000000;
    }

    if(DP[R][B][state] > -0.5){
        return DP[R][B][state];
    }

    double ret;

    if(state == 1){
        ret = fun(R, B -1, 0);
    }else{
        ret = ((double)B/(double)(R+B))*fun(R,B-1,1)+ ((double)R/(double)(R+B))*fun(R-1,B,1);
    }
    DP[R][B][state] = ret;
    return ret;
}

int main()
{
    int test;
    scanf("%d", &test);
    int R, B;
    memset(DP,-1,sizeof(DP));

    for(int tc = 1; tc <= test; tc++)
    {
        scanf("%d %d", &R, &B);

        printf("Case %d: ",tc);
        if(B== 0)
        {
            printf("0.00000000\n");
        }
        else if(R == 0)
        {
            printf("1.0000000000\n");
        }
        else
        {
            double ans = fun(R, B, 0);
            printf("%.15lf\n",ans);
        }
    }
}
