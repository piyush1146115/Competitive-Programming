#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define mp make_pair
#define pii pair<int, int>
#define pll pair<ll, ll>

int f[15], s[15];
int main()
{
    int n, m;

    cin >> n >> m;

    for(int i=  0; i < n; i++)
    {

        int k;
        cin >> k;
        f[k] = 1;
    }

    for(int i = 0; i < m; i++)
    {

        int k;
        cin >> k;
        s[k] = 1;
    }


    for(int i = 0; i <= 9; i++){
        if(f[i] == 1 && s[i] == 1){
            cout << i << endl;
            return 0;
        }
    }

    int ans = 0;
    for(int i = 0; i <= 9; i++){
        if(f[i] == 1){
            f[i] = 0;
            ans = i;
            memset(f, 0, sizeof(f));
            break;
        }
        if(s[i] == 1){
            s[i] = 0;
            ans = i;
            memset(s, 0, sizeof(s));
            break;
        }
    }
    for(int i = 0; i <= 9; i++){
        if(f[i] == 1){
            f[i] = 0;
            ans *= 10;
            ans += i;
            break;
        }
        if(s[i] == 1){
            s[i] = 0;
            ans *= 10;
            ans += i;
            break;
        }
    }
    cout << ans << endl;
}
