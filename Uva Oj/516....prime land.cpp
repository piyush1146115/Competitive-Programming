#include<bits/stdc++.h>
using namespace std;

int power(int b, int p)
{
    int ans = 1;

    while(p){
        if(p & 1){
            ans *= b;
        }
        b *= b;
        p = p / 2;
    }
    return ans;
}

vector<int>prime;
int chk[10005];

void sieve()
{
    int i, j;
    prime.push_back(2);

    for(i = 3; i <= 105; i += 2){
        if(chk[i] == 0){
            for(j = i * i; j <= 10000; j += (i + i)){
                chk[j] = 1;
            }
        }
    }

    for(i = 3; i <= 10000; i += 2)
        if(chk[i] == 0)
            prime.push_back(i);
}

int main()
{
    sieve();
    map <int, int> mp;
    vector <int> pf, ans;
    int i, j, n;
    string s;
    while(getline(cin, s)){
        if(s == "0")
            break;
        stringstream ss(s);

        while(ss >> j){
            pf.push_back(j);
        }

        n = 1;

        for(i = 0; i < pf.size() -1; i += 2){
            n *= power(pf[i], pf[i + 1]);
        }

        n--;
        if(n == 1){
         ans.push_back(2);
        }
        for(i = 0; prime[i] <= sqrt(n); i++){
            if(n % prime[i] == 0){
                    int c = 0;
                ans.push_back(prime[i]);
                while( n % prime[i] == 0){
                    n /= prime[i];
                    c++;
                }
                mp[prime[i]] = c;
            }
        }

        if(n > 1)
        {
            ans.push_back(n);
            mp[n]++;
        }

        sort(ans.begin(), ans.end());
        printf("%d %d",ans[ans.size() - 1], mp[ans[ans.size() - 1]]);

        for(i = ans.size() - 2; i >= 0; i--){
            printf(" %d %d",ans[i], mp[ans[i]]);
        }
        printf("\n");
        mp.clear();
        ans.clear();
        pf.clear();
    }
return 0;
}
