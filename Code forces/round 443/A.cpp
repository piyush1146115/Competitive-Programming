#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define mp make_pair
#define pii pair<int, int>
#define pll pair<ll, ll>
#define DEBUG(x) cout<<#x<<": "<<x<<endl
#define ff first
#define ss second

int main()
{
    int n;

  cin >> n;

  pii ara[1005];

  for(int i =  1 ; i <=n ;i++)
  {
      cin >> ara[i].ff >> ara[i].ss;
  }
  int cnt = 1;
  int ans;

  for(int i = 1; ; i++){

    if(i >= ara[cnt].ff){
        int dif = i - ara[cnt].ff;

//    DEBUG(ara[cnt].ff);
//    DEBUG(dif);
//    DEBUG(ara[cnt].ss);
//    DEBUG(i);
//    getchar();
        if(dif % ara[cnt].ss == 0){
            cnt++;
        }
    }
    if(cnt == n + 1){
        ans = i;
        break;
    }
  }

  cout << ans << endl;
 // main();
}
