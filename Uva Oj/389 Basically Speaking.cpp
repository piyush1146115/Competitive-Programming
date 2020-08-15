#include<bits/stdc++.h>
using namespace std;
int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

   long long int i,k, j, ba, cba, n, invalid;
    string s, ans;
    double temp;

    while(cin >> s >> ba >> cba){
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
                    //cout << k << endl;
                temp = pow(ba, j);
                j++;
                n += (k * temp);
                }
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

            if(ans.size() > 7){
                printf("  ERROR\n");
            }
            else{
                 cout<<setw(7)<<ans<<endl;
            }

        ans.clear();
        s.clear();
    }
    return 0;
}

