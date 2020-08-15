#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mxx 1005
int dp[mxx][mxx];
//char a[mxx], b[mxx];
string a,b;
int n;

int fun(int p1, int p2, int c, int d)
{
    if(abs(c - d) > 1)
        return 0;

    if(p1 == n && p2 == n)
        return 1;

    if(dp[p1][p2] != -1)
        return dp[p1][p2];

    int ret = 0;

    if(p1 < n)
    {
        int c1 = a[p1] - '0';
        if(c1 == 1)
            ret = fun(p1 + 1, p2,c + 1, d );
        else
            ret = fun(p1 + 1, p2, c, d + 1);
    }
    int ret1 = 0;
    if(p2 < n)
    {
        int c2 = b[p2] - '0';

        if(c2 == 0)
            ret1 = fun(p1, p2 + 1, c, d + 1);
        else
            ret1 = fun(p1, p2 + 1, c + 1, d);
    }

    dp[p1][p2] = ret1 | ret;
    return ret1 | ret;
}

vector<int> ans;

void path(int p1, int p2, int c, int d)
{
//    cout << p1 << " " << p2 << " " << c << " " << d << endl;
//    getchar();

    if(abs(c - d) > 1)
        return ;

    if(p1 == n && p2 == n)
        return;

    int r1, r2, r3, r4;
    r1 = r2 =  r3 = r4 = 0;

    if(p1 < n)
    {
        int ch = a[p1] - '0';

        if(ch == 1)
        {
            r1 = fun(p1 + 1, p2, c + 1, d);
        }
        else
        {
            r2 = fun(p1 + 1, p2, c, d + 1);
        }
    }
    if(p2 < n)
    {
        int ch = b[p2] - '0';

        if(ch == 1)
        {
            r3 = fun(p1, p2 + 1, c + 1, d);
        }
        else
        {
            r4 = fun(p1, p2 + 1, c, d + 1);
        }
    }

    if(r1 == 1)
    {
        ans.push_back(1);
        path(p1 + 1, p2, c + 1, d);
    }
    else if(r2 == 1)
    {
        ans.push_back(1);
        path(p1 + 1, p2, c, d + 1);
    }
    else if(r3 == 1)
    {
        ans.push_back(2);
        path(p1, p2 + 1, c + 1, d);
    }
    else
    {
        ans.push_back(2);
        path(p1, p2 + 1, c, d + 1);
    }
}


int main()
{
    cin >>n >> a >> b;

//    ans |= fun(1, 0, 1);
//    ans |= fun(0, 1, 2);
    memset(dp, -1, sizeof(dp));
//    int c1  = a[0] - '0';
//    int c2  = b[0] - '0';
//
//    int j = 0, k = 0, l = 0, m = 0;
//
//    if(c1 == 1)
//        j = fun(1, 0, 1, 0);
//    else
//        k = fun(1, 0, 0, 1);
//    if(c2 == 1)
//        l = fun(0, 1, 1, 0);
//    else
//        m = fun(0, 1, 0, 1);

    int flag = fun(0,0,0,0);

    if(!flag){
        printf("Impossible\n");
        return 0;
    }

    path(0,0,0,0);

    for(int i = 0; i < ans.size(); i++)
            printf("%d",ans[i]);

    printf("\n");

//    if( j == 1)
//    {
//        ans.push_back(1);
//        path(1, 0, 1, 0);
//        for(int i = 0; i < ans.size(); i++)
//            printf("%d",ans[i]);
//
//        printf("\n");
//    }
//    else if( k == 1)
//    {
//        ans.push_back(1);
//        path(1, 0, 0, 1);
//        for(int i = 0; i < ans.size(); i++)
//            printf("%d",ans[i]);
//
//        printf("\n");
//    }
//    else if( l == 1)
//    {
//        ans.push_back(2);
//        path(0, 1, 1, 0);
//        for(int i = 0; i < ans.size(); i++)
//            printf("%d",ans[i]);
//
//        printf("\n");
//    }
//    else if( m == 1)
//    {
//        ans.push_back(2);
//        path(0, 1, 0, 1);
//        for(int i = 0; i < ans.size(); i++)
//            printf("%d",ans[i]);
//
//        printf("\n");
//    }
//    else
//    {
//        printf("Impossible\n");
//    }
    ans.clear();

    return 0;
}
