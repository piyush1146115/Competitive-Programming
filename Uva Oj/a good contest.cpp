#include<bits/stdc++.h>
using namespace std;

struct co{
string han;
int bef, after;
}con[105];

int main()
{
    int n, i, flag = 0;

    cin >> n;

    for(i = 0; i < n; i++){
        cin >> con[i].han;
        cin >> con[i].bef >> con[i].after;
        if(con[i].bef >= 2400 && con[i].after > con[i].bef)
            flag = 1;
    }
    if(flag)
        cout << "YES\n";
    else
        cout << "NO\n";
}

