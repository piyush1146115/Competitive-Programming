#include<bits/stdc++.h>
using namespace std;

bool comp(int a, int b)
{
    return a > b;
}
int main()
{
    int cs, n, i, j, k;
    int ara[20050];

    cin >> cs;

    while(cs--){
        scanf("%d", &n);
        for(i= 0; i < n; i++)
            scanf("%d",&ara[i]);

        sort(ara, ara+ n, comp);
        int sum = 0;
        for(i = 2; i < n ; i += 3 )
            sum += ara[i];

        cout << sum << endl;
  }
  return 0;
}
