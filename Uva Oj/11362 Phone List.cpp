#include<bits/stdc++.h>
using namespace std;
int main()
{
   // freopen("input.txt", "r", stdin);

    string st[10005], temp;
    int i, j, k, sz, n, test, flag;

    scanf("%d", &test);

    while(test--){
        scanf("%d", &n);

        for(i = 0; i < n; i++){
            cin >> st[i];
        }
        sort(st , st + n);

        flag = 0;

        for(i = 0; i < n - 1; i++){
            for(j = i + 1; j < n; j++){
                sz = st[i].size();

                for(k = 0; k < sz; k++)
                    if(st[i][k] != st[j][k])
                        break;

                if(k == sz)
                    flag = 1;

                if(flag)
                    break;
            }
            if(flag)
                break;
        }
        if(flag){
            printf("NO\n");
        }
        else
            printf("YES\n");
    }
    return 0;
}
