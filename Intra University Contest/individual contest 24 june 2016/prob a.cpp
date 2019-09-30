#include<bits/stdc++.h>
using namespace std;
int main()
{
    int r, g, b, total, i, flag, p, q;

    while(cin >> r >> g >> b){
total = 0;
    while(1){
            flag = 1;
        if(r > 0 || g > 0 || b > 0)
        {
            total++;
            r -= 2;
            flag = 0;
        }
        if(g > 0 || b > 0 || r > 0){
            g -= 2;
            total++;
            flag = 0;
        }
        if(b > 0 || g > 0 || r > 0){
            b -= 2;
            total++;
            flag = 0;
        }
        if(flag)
            break;
    }

        printf("%d\n",total + 29);
    }
    return 0;
}
