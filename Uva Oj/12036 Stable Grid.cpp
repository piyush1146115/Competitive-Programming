#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n, test, i, j, k, flag, cs = 0;

    scanf("%d", &test);

    while(test--){
        flag = 0;
        scanf("%d", &n);
    int c[105];
        vector<int> v[105];
        set<int> s;

        memset(c, 0, sizeof(c));

        for(i = 0; i < n; i++){
            for(j = 0; j < n; j++){
                scanf("%d", &k);
                c[k]++;
                if(c[k] > n)
                    flag = 1;
            }
        }


        printf("Case %d: ", ++cs);

        if(!flag){
            printf("yes\n");
        }
        else{
            printf("no\n");
        }

    }
    return 0;
}
