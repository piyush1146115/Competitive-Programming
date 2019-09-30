#include<bits/stdc++.h>
using namespace std;
int ara[105];

int main()
{
    int n, k, m;

    cin >> n >> k >> m;

    for(int i = 0; i < n; i++){
     scanf("%d", &ara[i]);
    }

    int sum = 0;

    for(int i = 0; i < n - k; i++)
        sum += ara[i];

        sum += (k * m);

    cout << sum << endl;
}
