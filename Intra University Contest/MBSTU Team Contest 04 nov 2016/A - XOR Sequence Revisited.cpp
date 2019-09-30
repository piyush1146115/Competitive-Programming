#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long i, j, test, lf, rgt, tc = 0;

    j = 1;

   /* for(i = 1; i <= 50; i++){
        j = j ^ i;
        printf("%lld == %lld\n",i, j);
    }
    //printf("%d %d", 26 ^ 1,29 ^1 ^ 29 );

*/
    scanf("%lld",&test);

    while(test--){
        scanf("%lld %lld",&lf, &rgt);

        if(lf % 4 == 0)
            j = lf + 1;
        else if(lf % 4 == 1)
            j = 0;
        else if(lf % 4 == 2)
            j = lf;
        else if(lf % 4 == 3)
            j = 1;

        long long ans = j;

        for( i = lf + 1; i <= rgt; i++){
            if(i % 4 == 0)
            j = i + 1;
        else if(i % 4 == 1)
            j = 0;
        else if(i % 4 == 2)
            j = i;
        else if(i % 4 == 3)
            j = 1;
            //cout << "1 ----" << j << " " << ans << endl;
            ans = ans & j;
           // cout << "2 ----" << j << " " <<ans << endl;
            if(ans == 0)
                break;
        }
        printf("%lld\n",ans);
    }
    return 0;
}
