#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n, m, i, j, k,test,mul = 1, ans;

    cin >> test;

    for(i = 1; i <= test; i++){
        scanf("%d %d", &n, &m);
        ans = 0;
        while(m--){
            scanf("%d", &j);
            mul = 1;
            while(j--){
                scanf("%d",&k);
                mul *= k;
                mul %= n;
                //printf("mul = %d\n",mul);
            }
            ans += mul;
            ans %= n;
        }
        ans = ans % n;

        printf("%d\n",ans);
    }
    return 0;

}
