#include<bits/stdc++.h>
using namespace std;
int main()
{
    char st[1000];
    int i, j, k, ans, test;

    scanf("%d", &test);
    //getchar();

    while(test--){
        scanf("%s",st);
        ans = 0;
        int len = strlen(st);

        for(i = 0; i < len; i++){
                k = 0;
            for(j = i + 1; j < len; j++){
                if(st[j] != st[k]){
                    break;
                }
                k++;
                if(k > i)
                    k  = 0;
            }
            if(j  == len && k == 0){
                ans = i + 1;
                break;
            }
        }
        if(ans == 0)
            ans = len;

        printf("%d\n",ans);
        if(test)
            printf("\n");
    }

    return 0;
}
