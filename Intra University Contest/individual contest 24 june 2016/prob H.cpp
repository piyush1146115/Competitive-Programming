#include<bits/stdc++.h>
using namespace std;
int main()
{
    double a[50], b[50], V, total = 0.0, rat;
    int n, i, j;

    cin >> n >> V;

    for(i = 0; i < n; i++){
        cin >> a[i];
    }
    for(i = 0; i < n; i++)
        cin >> b[i];

    double mn = 10000000000.0;
    for(i = 0; i < n; i++){
        rat = b[i] / a[i];
        if(rat < mn)
            mn = rat;
    }
    for(i = 0; i < n; i++){
        total += (mn * a[i]);
    }
   printf("%lf\n", min(total, V));
}
