#include<bits/stdc++.h>
using namespace std;

vector<string> a, b;

int dp[1005][1005];

int lcs(int i, int j)
{
    if(i == a.size() || j == b.size())
        return 0;

    int res = 0;
    if(dp[i][j] != -1)
        return dp[i][j];

    if(a[i] == b[j]){
        res = max(res, 1 + lcs(i + 1, j + 1));
    }
    else{
        res = max(res, lcs(i + 1, j));
        res = max(res, lcs(i, j + 1));
    }

    return dp[i][j] = res;
}

int main()
{
    string s1, s2, temp;
    int tc = 0;

    while(getline(cin, s1)){
        getline(cin, s2);
        temp = "";


        for(int i = 0; i< s1.size(); i++){
            if(!isalpha(s1[i]) && !isdigit(s1[i]))
                s1[i] = ' ';
        }

        for(int i = 0; i < s2.size(); i++){
            if(!isalpha(s2[i]) && !isdigit(s2[i]))
                s2[i] = ' ';
        }

        stringstream ss(s1);

        while(ss >> temp){
            a.push_back(temp);
        }

        stringstream sk(s2);

        while(sk >> temp){
            b.push_back(temp);
        }

//        for(int i = 0; i < a.size(); i++)
//            cout <<  a[i] << endl;
//
//        for(int i = 0; i < b.size(); i++)
//            cout <<  b[i] << endl;


        if(a.size() == 0|| b.size() == 0){
            printf("%2d. Blank!\n",++tc);
            a.clear();
            b.clear();
            continue;
        }

        memset(dp, -1, sizeof(dp));

       int cnt =  lcs(0, 0);

        printf("%2d. Length of longest match: %d\n",++tc, cnt);
        a.clear();
        b.clear();
    }
}
