#include<bits/stdc++.h>
using namespace std;
int n;
int a[25], b[25];
int dp[25][25];

int lcs(int i, int j)
{
    if(i == n || j == n)
        return 0;
    int sum = 0;
    if(dp[i][j] != -1)
        return dp[i][j];

    if(a[i] == b[j]){
            sum = 1 + lcs(i + 1, j + 1);
    }
    else{
        sum = max(sum , lcs(i + 1, j));
        sum = max(sum, lcs(i, j + 1));
    }

    dp[i][j] = sum;
    return sum;
}

int main()
{
    string s;

    int flag = 0;
    while(getline(cin, s)){
        stringstream ss (s);
        if(s.size() <= 2){
            ss >> n;
            flag = 0;
            //cout << n << endl;
        }
        else{
                int temp;
            if(flag == 0){
                flag = 1;
                int i = 0;
                while(ss >> temp){
                    a[temp - 1] = i;
                    i++;
                }
//                for(i = 0; i < n; i++)
//                    cout << a[i] << " ";
//
//                cout << endl;
            }
            else{
             int i = 0;
                while(ss >> temp){
                    b[temp - 1] = i;
                    i++;
                }
            memset(dp, - 1, sizeof(dp));
            int ans = lcs(0, 0);
            printf("%d\n",ans);
//                for( i = 0; i < n; i++)
//                    cout << b[i] << " ";
//
//                cout << endl;
            }
        }
    }
}
