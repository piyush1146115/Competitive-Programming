#include<bits/stdc++.h>
using namespace std;
int main()
{
    char sub[105][105], s[100];
    int i, j, k, test, d, n, cse = 0, ara[105];

    scanf("%d", &test);

    while(test--){
        cse++;

        scanf("%d", &n);

        for(i = 0; i < n; i++){
            scanf("%s",sub[i] );
            scanf("%d", &ara[i]);
        }

        scanf("%d", &d);
        scanf("%s", s);

        for(i = 0; i < n; i++){
            if(strcmp(sub[i], s) == 0){
                if(ara[i] <= d)
                    printf("Case %d: Yesss\n",cse);
                else if(ara[i] <= d + 5)
                    printf("Case %d: Late\n",cse);
                else
                    printf("Case %d: Do your own homework!\n",cse);

                break;
            }
        }
        if(i == n)
            printf("Case %d: Do your own homework!\n",cse);

    }

    return 0;
}
