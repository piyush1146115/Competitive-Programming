#include<bits/stdc++.h>
using namespace std;
int main()
{
    string s, s1, s2;
    int n, t, i, j, k, flag = 0;

    cin >> n >> t;
    cin >> s;

    for(i = 0; i < n ;i ++){
            if(s[i] == '.')
            break;
        s1 += s[i];
    }
    for(j = i + 1; j < n; j++)
    {
        s2 += s[j];
        if(j  + 1< n)
        if(s[j + 1] >= '5'){
                flag = 1;
                s2 += s[j+ 1];
            break;
        }
    }


    if(flag)
    for(i = s2.size() - 1; i >= 1; i--){
        if(t > 0)
        {
            if(s2[i] >= '5'){
                    s2[i- 1] += 1;
                s2.erase(s2.begin() + i);
                t--;
                if(s2.size() == 1)
                    break;
            }
            else{
                break;
            }
        }
        else
            break;
    }

    if(s2[0] >= '5' && t > 0){
        s1[s.size() - 1]++;
        s = s1;
    }
    else
    s = s1 + "." + s2;

    cout << s << endl;
}
