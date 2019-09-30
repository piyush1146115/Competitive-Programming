#include<bits/stdc++.h>
using namespace std;
int flag[30];
int main()
{
    int n;
    cin >> n;
    string s;
    for(int i = 0; i < n; i++)
    {
        cin >> s;
        memset(flag, 0, sizeof(flag));

        int yes = 1, cnt = 0;
        for(int i = 0; i < s.size(); i++)
        {
            flag[s[i]- 'a']++;
            if(flag[s[i]- 'a'] > 1){
                yes = 0;
            }
        }

        for(int i = 0; i < 26; i++)
        {
            if(flag[i])
            {
                cnt++;
            }
            else
            {
                if(cnt > 0 && cnt != (s.size())){
                    yes = 0;
                }
            }
        }

        if(yes)
        {
            cout << "Yes\n";
        }
        else
        {
            cout << "No\n";
        }
    }

}
