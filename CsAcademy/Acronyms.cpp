#include<bits/stdc++.h>
using namespace std;

string s[100005];
int mp[100], cp[30];

int main()
{
    int n;
    cin >> n;

    for(int i = 0; i < n; i++)
        cin >> s[i];
   int cnt = 0;

   for(int i = 0; i < n; i++)
        mp[s[i][0]- 'a']++;

        for(int i = 0; i < n; i++){
            mp[s[i][0] - 'a']--;
            int j;
            memset(cp, 0, sizeof(cp));

            for( j = 0; j < (int)s[i].size(); j++){
               cp[s[i][j] - 'a']++;
            }

            for( j = 0; j < 26; j++){
                if(cp[j] > mp[j])
                    break;
            }

            if(j == 26)
                cnt++;

            mp[s[i][0] - 'a']++;

        }

   cout << cnt << endl;
}
