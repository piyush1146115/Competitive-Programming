#include<bits/stdc++.h>
using namespace std;
int main()
{
    char str[150];
    int ara[150], i, test, cse = 0, n;

    cin >> test;
    getchar();
    while(test--){
        memset(ara, 0, sizeof(ara));
        cse++;
        gets(str);
        int len = strlen(str);

        for(i = 0; i < len; i++){
            if(str[i] == 'D')
                ara[i] = -1;
            else if(str[i] == 'B'){
                ara[i] = -1;
                if(i  > 0)
                    ara[i - 1] = -1;
                if(i - 2 >= 0)
                    ara[i - 2] = -1;
            }
            else if(str[i] == 'S'){
                ara[i] = -1;
                if(i - 1 >= 0)
                    ara[i- 1] = -1;
                if(i + 1 < len)
                    ara[i + 1] = -1;
            }
        }
        int cont = 0;
    for(i = 0; i < len; i++)
        if(ara[i] == 0)
        cont++;

    printf("Case %d: %d\n",cse, cont);
    }
    return 0;
}
