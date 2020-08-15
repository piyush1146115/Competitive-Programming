#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long n, m, k, i, j;

    cin >> n >> m;
    if(m > n){
        cout << m << endl;
    }
    else{
    if(n % m == 0){
        i = n + m;
    }
    else{
        k = n - m;
        j = k % m;
        i = n + (m - j);
    }
    cout << i << endl;
    }
}
