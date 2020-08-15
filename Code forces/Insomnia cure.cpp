#include<bits/stdc++.h>
using namespace std;
int main()
{
    int k, l, m, n, d, i, cont = 0;

    cin >> k >> l >> m >> n >> d;

    for(i = 1; i <= d; i++){
        if(i % k == 0)
            cont++;
        else if(i % l == 0)
            cont++;
        else if(i % m == 0)
            cont++;
        else if(i % n == 0)
            cont++;
    }
    cout << cont << endl;

    return 0;
}
