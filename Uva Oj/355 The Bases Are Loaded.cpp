#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

   long long int i,k, j, ba, cba, n, invalid;
    string s, ans;
    double temp;

    while(cin >> ba >> cba >> s){
        invalid = 0;
        n = 0;
        j = 0;
        for(i = s.size() - 1; i >= 0; i--){
            if(s[i] >= '0' && s[i] <= '9'){
                k = s[i] - 48;
            }
            else{
                k = s[i] - 55;
            }
            if(k >= ba || k < 0 || ba >= 17 || ba <= 1 || cba >= 17 || cba <= 1){
                invalid = 1;
                break;
            }
            else{
                    //cout << k << endl;
                temp = pow(ba, j);
                j++;
                n += (k * temp);
            }
        }
        if(invalid){
            cout << s << " is an illegal base " << ba << " number\n";
        }
        else{
                if(n == 0){
                    ans.push_back(48);
                }
            while(n != 0){
                k = n % cba;
                if(k >= 10){
                    k += 55;
                }
                else{
                    k += 48;
                }
                ans.push_back(k);
                n /= cba;
            }
            reverse(ans.begin(), ans.end());

            cout << s << " base " << ba << " = " << ans << " base " << cba << endl;
        }
        ans.clear();
        s.clear();
    }
    return 0;
}
