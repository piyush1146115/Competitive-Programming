#include<bits/stdc++.h>
using namespace std;
#define ll long long
int mp[100000 * 3], ara[100000 * 3];
int main()
{

    int n;
    scanf("%d", &n);
    int mx = 0;
    for(int i = 0; i < n; i++){
        scanf("%d", &ara[i]);
        mp[ara[i]]++;
        mx = max(mx, mp[ara[i]]);
    }

    if(mx == n){
        printf("0\n");
    }else{
        printf("%d\n", n - mx);
        int pos;
        for(int i = 0; i < n; i++){
            if(mp[ara[i]] == mx){
                pos = i;
                break;
            }
        }

        for(int i = pos; i > 0; i--){
            if(ara[i - 1] > ara[i]){
                printf("%d %d %d\n",2, i -1 + 1 , i+1);
                ara[i - 1] = ara[i];
            }else if(ara[i - 1] < ara[i]){
                printf("%d %d %d\n",1, i -1 +1, i+1);
                ara[i - 1] = ara[i];
            }
        }


        for(int i = pos; i < n - 1; i++){
            if(ara[i + 1] > ara[i]){
                printf("%d %d %d\n",2, i + 1+1 , i+1);
                ara[i + 1] = ara[i];
            }else if(ara[i + 1] < ara[i]){
                printf("%d %d %d\n",1, i + 1 +1, i+1);
                ara[i + 1] = ara[i];
            }
        }
    }


}
