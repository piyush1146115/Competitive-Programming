#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n, freq[30], i;
    string s;

    scanf("%d",&n);

    while(n--){
        cin >> s;
        memset(freq, 0, sizeof(freq));

        for(i = 0; i < s.size(); i++)
        {
           freq[s[i] - 'a']++;
        }
        sort(s.begin(), s.end());

        for(i = 1; i < s.size(); i++){
            if(freq[s[i] - 'a'] > 1){
                freq[s[i]- 'a']--;
                s[i] = s[0];
            }
        }

        sort(s.begin(), s.end());

        cout << s << endl;
    }
    return 0;
}
