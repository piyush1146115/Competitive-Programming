#include<bits/stdc++.h>
using namespace std;
int ara[1000000];
int main()
{
    int n, i, j, ans = 0;

    cin >> n;

    for(i = 1; i <=n ;i++){
        scanf("%d", &ara[i]);
    }

    for(i = 1; i < n; i++){
        if(ara[i] > ara[i + 1]){
            ans = i;
        }
    }

    printf("%d\n",ans);

    return 0;
}
