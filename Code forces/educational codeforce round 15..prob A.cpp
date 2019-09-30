#include<bits/stdc++.h>
using namespace std;
int ara[100005];
int main()
{
    int n, i, j;

    scanf("%d", &n);
    for(i = 0; i < n; i++){
        scanf("%d" ,&ara[i]);
    }
    int co = 1, mx = 1;

    for(i = 0; i < n - 1; i++){
        if(ara[i] < ara[i + 1]){
            co++;
        }
        else{
            co = 1;
        }
        mx = max(co, mx);
    }

    cout << mx << endl;
}
