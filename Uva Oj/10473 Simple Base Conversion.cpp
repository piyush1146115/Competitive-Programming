#include<bits/stdc++.h>
using namespace std;

void hex(string s)
{
    long long i, j, k, ans;
    double temp;
    ans = 0;
    k = 0;
    for(i = s.size() -1; i >= 2;i--){
            if(s[i] >= 'A' && s[i] <= 'Z'){
                j = s[i] - 55;
            }
            else{
                j = s[i] - 48;
            }
        temp = pow(16, k);
        k++;
     ans += (j *temp);
    }

    cout << ans << endl;
}

void dec(string s){
long long n, k, j;
string ans;
stringstream ss(s);

ss >> n;
if(n == 0)
    ans.push_back(48);

    while(n != 0){
        j = n % 16;
        n/= 16;
        if(j > 9){
            ans.push_back(j + 55);
        }
        else{
            ans.push_back(j + 48);
        }
    }
    ans += "x0";
    reverse(ans.begin(), ans.end());
    cout << ans << endl;
}


int main()
{
    //freopen("input.txt", "r", stdin);
   // freopen("output.txt", "w", stdout);

    string s;
    int i, j;

    while(cin >> s){
        if(s[0] == '-')
            break;

       else if(s[1] == 'x'){
            hex(s);
        }
        else{
            dec(s);
        }
    }
    return 0;
}
