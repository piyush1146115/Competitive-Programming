#include<bits/stdc++.h>
using namespace std;
int main()
{
    unsigned long long n, i, sum;

    cin >> n;
    sum = 2;
    for(i = 1; ; i++){
        if(sum >= n){
            break;
        }
        sum *= 2;
    }

    cout << i << endl;
}
