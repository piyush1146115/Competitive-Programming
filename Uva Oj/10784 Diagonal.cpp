#include<bits/stdc++.h>
using namespace std;
int main()
{
    double n, ans , temp;
    int cs = 0;

    while(cin  >> n){
        if(n == 0)
            break;
        temp = (3 + sqrt(9 + (8 * n)))/ 2;
        ans = ceil(temp);

        printf("Case %d: %.0lf\n", ++cs, ans);
    }
    return 0;
}
