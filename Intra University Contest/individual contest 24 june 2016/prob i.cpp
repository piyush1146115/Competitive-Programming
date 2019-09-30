#include<bits/stdc++.h>
using namespace std;
int chk[10005];
int main()
{
    int i, j, k, rem, n, cnt = 0;
    string s, num;
    vector <string> v;
    cin >> n;

    for(i = 0; i < n; i++)
    {
        cin >> s;
        v.push_back(s);
    }
    /*for(i = 0; i < v.size(); i++)
        cout << v[i] << endl;*/

    for(i = 0; i < v.size(); i++)
    {
        if(chk[i] == 0)
        {
            for(j = 0; j < v.size(); j++)
            {
                if(i == j)
                    continue;
                if(chk[j] == 0)
                {
                    num = v[i] + v[j];
                   // cout << num << endl;
                    rem = 0;
                    for(k = 0; k < num.size(); k++)
                    {
                        rem = ((num[k] - '0') + rem * 10) % 3;
                    }
                    if(rem == 0)
                    {
                        chk[i] = 1;
                        chk[j] = 1;
                        cnt++;
                        break;
                    }
                     num = v[j] + v[i];
                    //cout << num << endl;
                    rem = 0;
                    for(k = 0; k < num.size(); k++)
                    {
                        rem = ((num[k] - '0') + rem * 10) % 3;
                    }
                    if(rem == 0)
                    {
                        chk[i] = 1;
                        chk[j] = 1;
                        cnt++;
                        break;
                    }

                }
            }
        }

    }
    cout << cnt << endl;
}
