#include<bits/stdc++.h>
using namespace std;
int main()
{
    char str[5][200];
    long long int m[5], y[5], i , j;
    int test, cse = 0;
    scanf("%d", &test);
    while(test--){
        cse++;
        scanf("%s", str[1]);
        scanf("%lld, %lld", &m[1], &y[1]);
        scanf("%s", str[2]);
        scanf("%lld, %lld", &m[2], &y[2]);

        if(strcmp(str[1], "January") != 0){
            if(strcmp(str[1], "February") != 0){
                y[1]++;
            }
        }
        int ans = 0;

        ans = y[2] / 4 - (y[1] - 1) / 4;
		ans -= y[2] / 100 - (y[1] - 1) / 100;
		ans += y[2] / 400 - (y[1] - 1) / 400;

          if((y[2] % 4 == 0 && y[2] % 100 != 0) || (y[2] % 400 == 0)){
            if(strcmp(str[2], "January") == 0){
                ans--;
            }
            else if(strcmp(str[2], "February") == 0 && m[2] < 29)
                ans--;
          }
          printf("Case %d: %d\n", cse, ans);
    }
    return 0;
}
