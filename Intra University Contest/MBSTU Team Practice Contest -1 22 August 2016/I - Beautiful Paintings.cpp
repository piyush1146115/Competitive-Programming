#include<bits/stdc++.h>
using namespace std;
int ara[1005], vis[1005];
int main()
{
    int i, j, n, co = 0;

    scanf("%d", &n);

    for(i = 0; i < n; i++)
        scanf("%d", &ara[i]);

    sort(ara, ara + n);

    for(i = 0; i < n ; i++){
        for(j = 0; j < n; j++){
            if(ara[j] > ara[i]){
                  //  cout << ara[i] << " " << ara[j] << endl;
                if(vis[j] == 0){
                        //cout << ara[i] << " " << ara[j] << endl;
                    co++;
                    vis[j] = 1;
                    break;
                }
            }
        }
    }

    /*for(i = 0; i < n; i++)
        printf("%d  ",ara[i]);*/

    printf("\n");


    printf("%d\n", co);

    return 0;
}
