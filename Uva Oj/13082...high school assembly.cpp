#include<bits/stdc++.h>
using namespace std;
int main()
{
    int i, j, test, t = 0, n, ara[10005], ch, c;

    scanf("%d", &test);

    while(test--){
            t++;
            ch = 1;
            c = 0;
        scanf("%d",&n);
        for(i = 0; i < n; i++){
            scanf("%d",&ara[i]);
        }

        for(i = 0; i < n; i++){
            if(ara[i] == ch){
                c++;
                ch++;
            }
        }
        printf("Case %d: %d\n", t, n - c);
    }
    return 0;
}
