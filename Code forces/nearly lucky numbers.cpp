#include<bits/stdc++.h>
using namespace std;
int main()
{
    unsigned long long n;
    int i, cont = 0, j;

    cin >> n;
    while(n != 0){
        j = n % 10;
        if(j == 4 || j == 7)
            cont++;
        n /= 10;
    }
    if(cont == 7 || cont == 4)
        cout << "YES\n";
    else
        cout << "NO\n";

    return 0;
}
