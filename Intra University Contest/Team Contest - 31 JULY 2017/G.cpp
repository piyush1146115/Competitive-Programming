#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mxx 30005
#define mod 1000000007
ll ara[mxx];
ll n;

int main() {
    int test;
    scanf("%d", &test);

    for (int tc = 1; tc <= test; tc++) {

        scanf("%lld", &n);

        for (int i = 0; i < n; i++) {
            scanf("%lld", &ara[i]);
        }
        int cnt = 0;
        //int flag[30005] = {0};
        for (int i = 0; i < n; i++) {
            if (ara[i] == 0)
                continue;
            for (int j = i + 1; j < n; j++) {
                if (ara[j] == 0)
                    continue;
                if ((ara[i]  * ara[j]) % mod == 1 ) {
                    cnt++;
                    ara[i] = 0;
                    ara[j] = 0;
                    break;
                }
            }
        }
        printf("Case #%d: %d\n",tc,cnt);
    }


}
