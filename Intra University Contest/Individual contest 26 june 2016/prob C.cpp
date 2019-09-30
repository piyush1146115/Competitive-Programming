#include<bits/stdc++.h>
using namespace std;
long long ara[300010];
int main()
{
    long long n, sum = 0, i, j;

        cin >> n;

        for(i = 0; i < n; i++)
            scanf("%I64d",&ara[i]);

        sort(ara, ara + n);
        for(i = 0; i < n; i++){
            j = i + 1;
            sum += abs(j - ara[i]);
        }

        cout << sum << endl;
}
