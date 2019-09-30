#include<bits/stdc++.h>
using namespace std;
vector <long long int> v;
long long gcd(long long a, long long b){
    if( b == 0)
        return a;
    else
        return gcd(b , a % b);
}
int main()
{
    long long i, j, dif, ans;
    string s;

    while(getline(cin, s)){
        if(s == "0")
            break;

        stringstream ss(s);

        while(ss >> j){
                if(j != 0)
            v.push_back(j);
        }
        ans = 0;

        for(i = 1; i < v.size(); i++){
            dif = abs(v[i] - v[i - 1]);
            ans = gcd(ans, dif);
        }
        cout << ans << endl;
        v.clear();
    }
    return 0;
}
