#include<bits/stdc++.h>
using namespace std;
int main()
{
    unsigned long long ara[5];

    cin >> ara[0] >> ara[1] >> ara[2];

    sort(ara, ara+ 3);

    unsigned long long k, sum;

    k = ara[2] - 1;

    sum = 0;
    if(k >= ara[0])
    sum += (k - ara[0]);

    if(k >= ara[1])
        sum += (k - ara[1]);

    cout << sum << endl;
}
