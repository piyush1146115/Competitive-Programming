#include<bits/stdc++.h>
using namespace std;
int ara[100005];
int main()
{
    int n, a, sum = 0, cont = 0;

    cin >> n;

    for(int i = 0; i < n; i++){
        scanf("%d", &ara[i]);
    }

    sort(ara, ara + n);


    cout << cont << endl;

    return 0;
}
