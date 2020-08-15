#include<bits/stdc++.h>
using namespace std;
#define ll long long
int n, m;
int ara[200005], freq[200005];
int main()
{
    scanf("%d %d", &n, &m);

    ll div = n/ m;

    for(int i = 0; i < n; i++){
        scanf("%d", &ara[i]);
        freq[ara[i] % m]++;
    }



    ll ans = 0;


    int temp = 0;

}
