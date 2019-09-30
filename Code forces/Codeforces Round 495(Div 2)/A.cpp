#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n, d;
ll ara[105];

int main()
{
    cin >> n >> d;

    for(int i = 0; i < n; i++){
        cin >> ara[i];
    }

    ll sum = 0, cnt = 1;
    sort(ara, ara + n);

    for(int i = 0; i < n - 1; i++){
        if(ara[i] + (2*d) <= ara[i + 1]){
            cnt++;
        }
    }
    for(int i = 1; i < n; i++){
        if(ara[i] - (2*d) > ara[i - 1]){
            cnt++;
        }
    }
    cnt++;

    cout << cnt << endl;
}
