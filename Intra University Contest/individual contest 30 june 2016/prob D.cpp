#include<bits/stdc++.h>
using namespace std;
int main()
{
    int g[2], b[2], l = 1, r = 1;

    cin >> g[0] >> g[1];
    cin >> b[0] >> b[1];

    /*if((b[0] <= 0 && g[1] > 1) && (b[1] <= 0 && g[0] > 1) )
        flag = 0;
*/
    if(b[0] > (g[1] + 1) * 2)
        l = 0;
    if(b[1] > (g[0] + 1) * 2)
        r = 0;
    if(b[0] < (g[1] - 1))
        l = 0;
    if(b[1] < (g[0] - 1))
        r = 0;

    if(l || r)
        printf("YES\n");
    else
        printf("NO\n");

        return 0;
}
