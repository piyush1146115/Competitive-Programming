#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n, p, q, cont = 0;

    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> p >> q;
        if(q - p >= 2)
            cont++;
    }
    cout << cont << endl;

    return 0;
}
