#include<bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    int n, d, i, j, c = 0, mx = -1;

    cin >> n >> d;

    while(d--){
        cin >> s;
        int flag = 0;
        for(i = 0; i < s.size(); i++){
            if(s[i] == '0'){
                flag = 1;
                break;
            }
        }
        if(flag)
            c++;
        else
            c = 0;

        if(c > mx)
            mx = c;
    }
    cout << mx << endl;
}
