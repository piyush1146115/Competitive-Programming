#include<bits/stdc++.h>
using namespace std;

int gcd(int a, int b){
    if(a % b == 0)
        return b;
    else return gcd(b, a % b);
}
int main()
{
    int i, j, ans, ara[105], n, test;
    string s;

    cin >> test;
    getline(cin, s);

    while(test--){
        getline(cin, s);
        stringstream is(s);
        n = 0;
        while(is >> ara[n]) n++;

        ans = 0;
        for(int i = 0; i < n; i++){
            for(int j = i + 1; j < n; j++){
                ans = max(ans, gcd(ara[i],ara[j]));
            }
        }
        cout << ans << endl;
    }
    return 0;
}
