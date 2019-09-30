#include<bits/stdc++.h>
using namespace std;
int main()
{
    //freopen("input.txt", "rt", stdin);
    int n, b, h, w, p, cost, minimum, bed;
    int i, j, k;
    while(scanf("%d %d %d %d", &n, &b, &h, &w) != EOF){

        minimum = 1000000;
        cost = 1000000;
        for(i = 1; i <= h; i++){
            scanf("%d", &p);

            for(j = 1; j <= w; j++){
                scanf("%d", &bed);
                if(bed >= n)
                    cost = p * n;
            }
            minimum = min(cost, minimum);
           // printf("%d %d\n",cost, minimum);
        }
        if(minimum <= b){
            printf("%d\n",minimum);
        }
        else{
            printf("stay home\n");
        }
    }
    return 0;
}
