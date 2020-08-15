#include<bits/stdc++.h>
using namespace std;
int dp[30][30];
string a, b;

int lcs(int i, int j)
{
    //cout << "ok\n";

    if(i == a.size() && j == b.size())
        return 0;
    if(i == a.size())
        return (b.size() - j);
    if(j == b.size())
        return (a.size() - i);

    if(dp[i][j] != -1)
        return dp[i][j];

    int ret = 999999;

    if(a[i] == b[j])
            ret = lcs(i + 1, j + 1);
    else{
        ret = min(ret, 1 + lcs(i + 1, j + 1));
        ret = min(ret, 1 + lcs(i, j + 1));
        ret = min(ret, 1 + lcs(i + 1, j));
    }
    return dp[i][j] = ret;
}

void path(int i, int j)
{
    //getchar();

     if(i == a.size() && j == b.size())
        return;

    if(i == a.size() && j < b.size()){
     //   return (b.size() - j);
     while(j != b.size()){
        printf("I%c%02d",b[j], j + 1);
        j++;
     }
     return;
    }

    if(j == b.size() && i < a.size()){

        while(i != a.size()){
            printf("D%c%02d",a[i], j + 1);
            i++;
        }
        return;
    }


    int x, y, z;

    if(a[i] == b[j]){
        path(i + 1, j + 1);
    }
    else{
            int mn;
        x = lcs(i + 1, j + 1);
        y = lcs(i + 1, j);
        z = lcs(i, j + 1);
        mn = min(x, min(y, z));

    //cout << i << " " << j << " " << a[i] << " " << b[j] <<" " << x <<" " << y << endl;
        if(x == mn){
            printf("C%c%02d",b[j],j + 1);
            path(i + 1, j + 1);
        }
        else if(y == mn){
            printf("D%c%02d",a[i], j + 1);
            path(i + 1, j);
        }
        else{
            printf("I%c%02d",b[j],j + 1);
            path(i, j + 1);
        }
    }
}

int main()
{
    while(cin >> a){
        if(a == "#")
            break;
        cin >> b;
        memset(dp, - 1, sizeof(dp));
        lcs(0, 0);
        path(0, 0);
        printf("E\n");
    }
    return 0;
}
