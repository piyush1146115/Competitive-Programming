#include<bits/stdc++.h>
using namespace std;
int main()
{
    string a, b;
    int c4 = 0, c7 = 0, i, j, k;

    cin >> a >> b;

    for(i = 0; i < a.size(); i++){
        if(a[i] != b[i]){
            if(b[i] == '7')
                c7++;
            else
                c4++;
        }
    }
    cout << max(c4, c7) << endl;

    return 0;
}
