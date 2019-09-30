#include<bits/stdc++.h>
using namespace std;
int main()
{
    //freopen("input.txt", "r", stdin);

    int test, s, a, f, i, j, st[50005], av[50005];

    cin >> test;

    while(test--){
        scanf("%d %d %d",&s, &a, &f);

        for(i = 0; i < f; i++){
            scanf("%d %d",&st[i], &av[i]);
        }
        sort(st, st + f);
        sort(av, av + f);

        if(f % 2 != 0)
            i = f/2 + 1;
        else
            i = f / 2;

        printf("(Street: %d, Avenue: %d)\n",st[i - 1], av[i -1]);
    }
    return 0;
}
