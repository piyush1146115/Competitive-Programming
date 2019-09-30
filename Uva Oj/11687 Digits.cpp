#include<bits/stdc++.h>
using namespace std;
int f(int n){
int cnt = 0;
while( n != 0){
    n /= 10;
    cnt++;
}
return cnt;
}
int main()
{
    string s;
    int i, j, k, ans, n;

    while(cin >> s){
        if(s == "END")
            break;

        n = s.size();
        ans = 0;
        j = n;
        k = n;
        ans = 1;
        while(j != 1){
        j = f(k);
        k = j;
        ans++;
        }
        if(s != "1")
            ans ++;

        cout << ans << endl;
    }
    return 0;
}
