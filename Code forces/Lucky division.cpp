#include<bits/stdc++.h>
using namespace std;
vector <int> lc;
void lucky()
{
    int i, j, k;

    for(i = 4; i <= 1000; i++){
    j = i;
    int flag = 1;
    while(j != 0){
        k = j % 10;
        j /= 10;
        if(k != 4 && k != 7)
        {
            flag = 0;
            break;
        }
    }
    if(flag)
        lc.push_back(i);
    }
}
int main()
{
    lucky();

    int n, flag = 0, i;

    cin >> n;

    for(i = 0; i < lc.size(); i++){
        if(n % lc[i] == 0){
            flag = 1;
            break;
        }
    }
    if(flag)
        cout << "YES\n";
    else
        cout << "NO\n";

    return 0;
}
