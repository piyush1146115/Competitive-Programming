#include<bits/stdc++.h>
using namespace std;
int main()
{
    int i, j,ans, n, t, m, c, ara[1500], tour;

    cin >> c;

    while(c--){
        scanf("%d %d %d", &n, &t, &m);

       for(i = 0; i < m; i++){
        scanf("%d",&ara[i]);
       }
       sort(ara, ara + m);
       ans = 0;
    tour = 0;
       if(m % n == 0){
        ans = ara[n - 1] + 2 * t;
        j = n;
        tour++;
       }
       else{
        ans = ara[m % n - 1] + 2 * t;
        j = m % n;
        tour++;
       }
      for( ; j < m ; j += n){
        ans += 2 * t;
        ans = max(ans, ara[j + n - 1] + 2 * t);
        tour++;
      }
      ans -= t;
      cout << ans << " " << tour << endl;
    }
    return 0;
}
