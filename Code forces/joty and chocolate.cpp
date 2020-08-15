#include<bits/stdc++.h>
using namespace std;

int main()
{
    long long n, a, b, sum = 0, p, q, i, j, k, m;
    cin >> n >> a >> b >> p >> q;

    if(p >= q){
        j = n / a;
        sum += (p * j);
          k = n / b;

        sum += (k * q);
        m = a * b;

        k = n / m;

        sum -= (k * q);
    }
    else{
        j = n / b;
        sum += (j * q);
        k = n / a;

        sum += (k * p);
        m = a * b;

        k = n / m;

        sum -= (k * p);
    }

    cout << sum << endl;
}
