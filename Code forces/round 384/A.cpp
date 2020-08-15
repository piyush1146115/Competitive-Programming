#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n ,p1, p2, a, b, i , j;

    string s;

    cin >> n >> a >> b;
    cin >> s;

    int cost = 0;

    //p1 = min(a, b);
   // p2 = max(a, b);

    if(s[a - 1] == s[b - 1]){
        //cout << cost <<endl;
        cost = 0;
    }
    else{
        cost = 1;
        }
        cout << cost << endl;


    return 0;
}
