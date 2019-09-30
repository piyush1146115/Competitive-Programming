#include<bits/stdc++.h>
using namespace std;
int main()
{
    char str[5];
    long long int op, n, m, d = 0;

    cin >> op >> n;

    while(op--){
    cin >> str >> m;
    if(str[0] == '+'){
        n += m;
    }
    else if(str[0] == '-'){
        if(n - m < 0){
            d++;
        }
        else{
            n -= m;
        }
    }
    }
    cout << n <<" " << d;
}
