#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    int n;

    cin >> n;
    int tp;
    string s;
    long long k;

    map<string, long long> mp;

    for(int i = 0; i < n; i++)
    {
        cin >> tp;

        if(tp == 1)
        {
            cin >> s >> k;
            mp[s] += k;
        }
        else if(tp == 2)
        {
            cin >> s;
            if(mp.find(s) != mp.end())
                mp.erase(s);
        }
        else
        {
           cin >> s;
           cout << mp[s] << endl;
        }
    }
}
