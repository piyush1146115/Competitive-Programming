#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n, i, j;
    int ara[12];
    char str[20];

    memset(ara, 0, sizeof(ara));
    while(scanf("%d", &n), n){
        getchar();
        gets(str);
            if(strcmp(str, "too high") == 0){
                for(i = n ; i <= 10; i++){
                    ara[i] = -1;
                }
            }
            else if(strcmp(str, "too low") == 0){
                for(i = 0; i <= n; i++)
                    ara[i] = -1;
            }
            else{
                if(ara[n] == 0)
                    printf("Stan may be honest\n");
                else
                    printf("Stan is dishonest\n");

                memset(ara, 0, sizeof(ara));
            }
    }
    return 0;
}
