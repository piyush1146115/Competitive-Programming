#include<bits/stdc++.h>
using namespace std;
int ara[100005];
int main()
{
    string s;
   long long  int i, j, k, n;

    while(getline(cin, s)){
        stringstream ss(s);
        n = 0;
        long long mx = -1, sum = 0;
        while(ss >> k){
            sum += k;
              if(sum < 0)
                sum = 0;
            //cout << sum << endl;
            mx = max(sum, mx);
        }
        printf("%lld\n", mx);
    }
    return 0;
}
