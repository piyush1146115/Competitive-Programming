#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n, len;
    char st[20];

    scanf("%d",&n);
    getchar();

    while(n--){
        gets(st);
        len = strlen(st);

        sort(st, st + len);

        do{
            printf("%s\n", st);
        }while(next_permutation(st, st + len));
        printf("\n");
    }
    return 0;
}
