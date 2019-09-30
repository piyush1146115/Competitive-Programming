#include<bits/stdc++.h>
using namespace std;
vector <int> indx[10005], val[10005];
int ara[10005];
int main()
{
    int r, c ,i, j, k, l, n;
    //freopen("input.txt", "r", stdin);
    while(scanf("%d %d", &r, &c) == 2){

        for(i = 1; i <= r; i++){

            scanf("%d", &k);
            for(j = 0; j < k; j++){
                scanf("%d",&ara[j]);
                indx[ara[j]].push_back(i);
            }
            for(j = 0; j < k ; j++){
                scanf("%d", &n);
                val[ara[j]].push_back(n);
            }
        }

        printf("%d %d\n",c, r);

        for(i = 1; i <= c; i++){
            if(indx[i].size() == 0){
                printf("0\n\n");
            }
            else{
                printf("%d", indx[i].size());

                for(j = 0; j < indx[i].size(); j++){
                    printf(" %d",indx[i][j]);
                }
                printf("\n");
                printf("%d",val[i][0]);
                for(j = 1; j < val[i].size(); j++){
                    printf(" %d", val[i][j]);
                }
                printf("\n");
            }
        }
        for(i = 0; i <= 10000; i++)
        {
            val[i].clear();
            indx[i].clear();
        }
    }
    return 0;
}
