#include<bits/stdc++.h>
using namespace std;
int main()
{
    //freopen("input.txt","r",stdin);
    char s[105][6];
    int n, q, i, j, k, pos, l_len, r_len;

    cin >> n;

    for(i = 0; i < n; i++)
        scanf("%s",s[i]);

    scanf("%d", &q);

    for(i = 1; i <= q; i++){
        scanf("%d", &pos);
        if(strcmp(s[pos - 1], "?") != 0)
            printf("%s\n",s[pos - 1]);
        else{
            l_len = 0;
            r_len = 0;
            j = pos - 1;

            while(strcmp(s[j], "?") == 0 && j >= 0){
                l_len++;
                if(j == 0)
                    l_len = 100000;
                j--;
            }

            j = pos - 1;
            while(strcmp(s[j], "?") == 0 && j < n){
            r_len++;
            if(j >= n - 1)
                r_len = 100000;
            j++;
            }

            if(r_len < l_len)
            {
                for(k = 1; k <= r_len; k++)
                    printf("left of ");

            printf("%s\n",s[pos +r_len - 1]);
            }

            else if(l_len < r_len){
                    for(k = 1; k <= l_len;k++)
                    printf("right of ");

                printf("%s\n",s[pos - l_len - 1]);
            }
            else if(l_len == r_len)
                printf("middle of %s and %s\n",s[pos - l_len - 1], s[pos + r_len - 1]);
        }
    }
return 0;
}
