#include<bits/stdc++.h>
using namespace std;
bool ara[10000010];
int  s, e, r, flag;

bool chk()
{
    int i;
    for(i = s; i < e; i++){

        if(ara[i] == 1){
            return false;
        }
        ara[i] = 1;
    }
    return true;
}

int main()
{
    int n, m, i, j, k;
    while(scanf("%d %d",&n, &m) == 2){
            if(m == 0 && n == 0)
            break;
        memset(ara, 0, sizeof(ara));
            flag = 1;
        for(i = 0; i < n; i++){
            scanf("%d %d",&s, &e);
            if(flag){
            if(!chk()){
                flag = 0;
            }
            }
        }

        for(i = 0; i < m; i++){
            scanf("%d %d %d",&s, &e, &r);
            while(s <= 1000000){
                 if(flag){
            if(!chk()){
                flag = 0;
            }
            }
            s += r;
            e += r;
            if(e > 1000000)
                e = 1000000;
            }
        }
        if(flag){
            printf("NO CONFLICT\n");
        }
        else
            printf("CONFLICT\n");
    }
    return 0;
}
