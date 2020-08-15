#include<bits/stdc++.h>
using namespace std;
#define MAX 15

int row[MAX], col[MAX];
int dp[MAX][MAX];
string s[MAX];

int fun(int left, int right)
{
    if(left >= right)
        return 0;
    if(dp[left][right] != -1)
        return dp[left][right];

    int ans = 1 << 30;

    for(int mid = left; mid < right; mid++){

        int opr_left = fun(left, mid);
        int opr_right = fun(mid + 1, right);
        int opr_merge = row[left] * col[mid] * col[right];
        int total = opr_left + opr_right + opr_merge;

        ans = min(ans, total);
    }
    dp[left][right] = ans;
    return ans;
}


void path(int left, int right)
{
    if(left >= right)
        return;

    s[left] = "(" + s[left];
    s[right].push_back(')');

    int ans = 1 << 30, ind = 0;

    for(int mid = left; mid < right; mid++){
        int opr_left = fun(left, mid);
        int opr_right = fun(mid + 1, right);
        int opr_merge = row[left] * col[mid] * col[right];
        int total = opr_left + opr_right + opr_merge;

        if(total < ans){
            ans = total;
            ind = mid;
        }
    }
    path(left, ind);
    path(ind +1, right);

}

void print(int n)
{
    for(int i = 1; i <= n; i++){
        int j = 0;

        while(j < s[i].size() && s[i][j] == '('){
                printf("%c",s[i][j]);
                j++;
              }
        printf("A%d",i);

        while(j < s[i].size() && s[i][j] == ')'){
            printf("%c",s[i][j]);
            j++;
        }
        if(i != n)
            printf(" x ");
    }
    printf("\n");
}

int main()
{
    int n, tc = 0;
    while(scanf("%d", &n) == 1){
        if(n == 0)
            break;
    memset(dp, -1, sizeof(dp));
        for(int i = 1; i <= n; i++){
            scanf("%d %d", &row[i], &col[i]);
        }
        for(int i = 0; i <= n; i++)
            s[i].clear();

        int ans = fun(1, n);
        path(1, n);
        printf("Case %d: ",++tc);
        print(n);
    }
    return 0;
}
