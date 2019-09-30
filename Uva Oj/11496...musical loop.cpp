#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n, i, j, ara[10005];

    while(scanf("%d",&n) == 1 && n != 0){
        for(i = 0; i < n; i++)
            scanf("%d",&ara[i]);
        ara[n] = ara[0];
        ara[n + 1] = ara[1];

        int cnt = 1;
        for(i = 1; i < n; i++){
            if(ara[i - 1] < ara[i] && ara[i + 1] < ara[i])
                cnt++;
            else if(ara[i - 1] > ara[i] && ara[i + 1] > ara[i])
                cnt++;
        }

        if(ara[n -1] > ara[n] && ara[n + 1] < ara[n])
            cnt--;
        else if(ara[n - 1] < ara[n] && ara[n +1] > ara[n] )
            cnt--;
        else if(ara[n - 1] == ara[n])
            cnt--;

        cout << cnt << endl;
    }
    return 0;
}
