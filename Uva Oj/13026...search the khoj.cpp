#include<bits/stdc++.h>
using namespace std;
int main()
{
    //freopen("input.txt", "r", stdin);
    char str[1005][15], phn[15];
    int test, i, j, len, cse = 0;

    scanf("%d",&test);

    while(test--){
        cse++;
        int n;
        scanf("%d",&n);

        for(i = 0; i < n; i++)
            scanf("%s",str[i]);

        scanf("%s",phn);
        int l2 = strlen(phn);
        printf("Case %d:\n",cse);
        for(i = 0; i < n ; i++){
            len = strlen(str[i]);
            if(len - l2 > 1)
                continue;

            int cont = 0;
            j = 0;
            while(j < len && cont <= 1)
            {
                if(str[i][j] != phn[j])
                    cont++;

                j++;
            }
            if(cont <= 1){
                printf("%s\n",str[i]);
            }
        }
    }
    return 0;
}
