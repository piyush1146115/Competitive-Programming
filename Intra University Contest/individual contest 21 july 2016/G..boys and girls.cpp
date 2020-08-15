#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int g, b, i;

    while(scanf("%d %d", &b, &g) == 2){
 if(b >= g){
        for(i = 0; i < b; i++){
            printf("B");
            if(g > 0){
                printf("G");
                g--;
            }
        }
    }
    else{
        for(i = 0; i < g; i++){
            printf("G");
            if(b > 0){
                printf("B");
                b--;
            }
        }
    }
    }
    return 0;
}
