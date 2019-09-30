#include<bits/stdc++.h>
using namespace std;
int main()
{
    int flag[100], test, cse = 0;
    scanf("%d", &test);

    while(test--){
        char str[25];

        scanf("%s", str);

        int len = strlen(str);
        int i;
        memset(flag, 0, sizeof(flag));
        for(i = 0; i < len; i++){
            flag[str[i]]++;
        }
        int low = 0;
        for(i = 65; i <= 90; i++)
            if(flag[i] > 1)
            low += flag[i];

            unsigned long long res  = 1;

            for(i )
    }

}
