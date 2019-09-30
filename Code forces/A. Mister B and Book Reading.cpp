#include<bits/stdc++.h>
using namespace std;
int main()
{
    int c, v0, v1, a, l;

    while(scanf("%d %d %d %d %d",&c, &v0, &v1, &a, &l) == 5){

        int i, sum = 0, add;

        for(i = 0; ; i++){
            if(i >= 1)
                add = v0 + (i * a);
            else
                add = v0;

            if(add > v1)
                add = v1;
            if(i >= 1)
                add -= l;

            sum += add;
            if(sum >= c)
                break;
        }
        printf("%d\n",i + 1);
    }
    return 0;
}
