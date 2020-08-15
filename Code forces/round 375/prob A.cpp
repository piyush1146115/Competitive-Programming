#include<bits/stdc++.h>
using namespace std;
int main()
{
    int ara[5], i, j, k;

    cin >> ara[0] >> ara[1] >> ara[2];

    sort(ara , ara+ 3);

    cout << fabs(ara[2] -ara[0]) << endl;

    return 0;
}
