#include<bits/stdc++.h>
using namespace std;
int main()
{
    int ara1[1500], ara2[1500], match, n, i, j, chk[55], k = 0, sol[4];

    memset(chk, 0, sizeof(chk));
    cin >> n;
    match =((n * (n - 1)) / 2) - 1;
    for(i = 0; i < match ; i++){
        scanf("%d %d",&ara1[i], &ara2[i]);
        chk[ara1[i]]++;
        chk[ara2[i]]++;
    }
    for(i = 1; i <= n; i++){
        if(chk[i] != n - 1){
            sol[k++] = i;
        }
    }
    vector <int> lose;
    for(i = 0; i < match; i++){
        if(sol[0] == ara1[i]){
            lose.push_back(ara2[i]);
        }
    }
    int flag = 0;

    for(i = 0; i < lose.size(); i++){
        for(j = 0; j < match; j++){
            if(ara1[j] == lose[i] && ara2[j] == sol[1]){
                flag = 1;
                break;
            }
        }
        if(flag)
            break;
    }
    if(lose.size() == 0){
        flag = 0;
    }
    if(flag)
        printf("%d %d\n",sol[0], sol[1]);
        else
            printf("%d %d\n",sol[1], sol[0]);
}
