#include<bits/stdc++.h>
using namespace std;

int main() {
    int test;

    scanf("%d", &test);

    for (int tc = 1; tc <= test; tc++) {
        string s, s1, s2, t;

        cin >> s;
        int n = s.size();

        for (int i = 0; i < s.size(); i++) 
        {

            if (s[i] == '?') 
            {

                char ch1, ch2, ch;

                if (i - 1 >= 0 && s[i - 1] != '?' && i + 1 < n && s[i + 1] != '?') 
                {

                    ch1 = s[i - 1];
                    int cnt1 = 0;

                    int  j = i - 1;

                    while (j >= 0 && s[j] == ch1) 
                    {
                        cnt1++;
                        j--;
                    }
                    
                    j = i + 1;
                    int cnt2 = 0;
                    ch2 = s[i + 1];
                    
                    while (j < n && s[j] == ch2) 
                    {
                        cnt2++;
                        j++;
                    }

                    if (ch1 != ch2) 
                    {
                        if (cnt1 <= cnt2) {
                            s[i] = ch1;
                        } else {
                            s[i] = ch2;
                        }
                    } 
                    else 
                    {
                        if (ch1 == '0')
                            s[i] = '1';
                        else
                            s[i] = '0';
                    }

                    i = j-1;
                } 
                else if ( i == 0) 
                {
                    int j = i;
                    while (j < n && s[j] == '?') {
                        j++;
                    }
                    if (j == n)
                        break;

                    if (s[j] == '0') {
                        s[j - 1] = '1';
                    }
                     else
                        s[j - 1] = '0';
                        
                        i = j-1;
                } 
                else 
                {
                    ch = s[i - 1];
                    int j = i;
                    //cout << "yes" << " " <<  i  << endl;
                    while (j < n && s[j] == '?') 
                    {

                        if (j + 1 < n && s[j + 1] != '?') 
                        {
                            if (s[j + 1] == '0')
                                s[j] = '1';
                            else
                                s[j] = '0';
                        } 
                        else if (ch == '0') 
                        {
							
                            s[j] = '1';
                            ch = '1';
                        }
                         else 
                        {
                            s[j] = '0';
                            ch = '0';
                        }
                        j++;
                    }
                    i = j -1;
                }
            }
        }

        int ans = 1, cnt = 1;
        for (int i = 1; i < n; i++) {
            if (s[i] == '?') {
                cnt = 1;
            } else if (s[i] == s[i - 1]) {
                cnt++;
            } else {
                cnt = 1;
            }
            ans = max(cnt, ans);
        }

        //cout << s << endl;
        printf("Case %d: %d\n", tc, ans);
    }
    return 0;
}
