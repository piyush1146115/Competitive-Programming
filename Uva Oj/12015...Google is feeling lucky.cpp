#include<bits/stdc++.h>

using namespace std;

int main()
{
    char str[15][105];
    int indicator[15], num[15];
    int a, b, i, test;

    scanf("%d",&test);

    for(i = 1; i <= test; i++){
        for(a = 0; a < 10; a++){
            scanf("%s",str[a]);
            scanf("%d",&num[a]);

            indicator[a] = num[a];
        }

        sort(num, num + 10);

        printf("Case #%d:\n",i);
        for(a = 0; a < 10; a++){
            if(indicator[a] == num[9]){
                printf("%s\n",str[a]);
            }
        }
    }
    return 0;
}
