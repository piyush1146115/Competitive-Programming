#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long n, i, j, sum = 1;

    while(cin >> n){
            i = 0;
        while(n != 0){
            n = n/2;
            i++;
        }
            cout << i << endl;
        }
    return 0;
}
