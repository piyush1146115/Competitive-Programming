#include<bits/stdc++.h>
using namespace std;
int main()
{
    int m, n, mx, mn;

    cin >> n >> m;
    if(n == 0 && m == 0){
        printf("0 0\n");
    }
    else if(n == 0){
        printf("Impossible\n");
    }
    else{
        mn = n;
        if(m - n > 0){
            mn += (m - n);
        }
        if(m > 0)
        mx = n + (m - 1);
        else
            mx = mn = n;

        printf("%d %d\n",mn, mx);
    }
    return 0;
}
