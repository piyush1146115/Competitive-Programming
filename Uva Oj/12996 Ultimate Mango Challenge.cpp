#include<bits/stdc++.h>
using namespace std;
int main()
{
    //freopen("input.txt", "r", stdin);

    int test, N, L, n[50], l[50], i, j, sum, t = 0;

    cin >> test;

    while(test--){
        t++;
        scanf("%d %d",&N, &L);

        for(i = 0; i < N; i++){
            scanf("%d",&n[i]);
        }

        for(i = 0; i < N; i++){
            scanf("%d",&l[i]);
        }
        sum = 0;
        int flag = 1;
        for(i = 0; i < N; i++){
            if(n[i] <= l[i] && sum + n[i] <= L){
                sum += n[i];
            }
            else{
                flag = 0;
                break;
            }
        }
        printf("Case %d: ",t);

        if(flag)
            printf("Yes\n");
        else
            printf("No\n");
    }
    return 0;
}
