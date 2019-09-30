
#include<bits/stdc++.h>
using namespace std;
   string fib[2000];
void f()
{

    int i, j, k;
    fib[0] = "1";
    fib[1] = "2";

    for(i = 2; i <= 1050; i++){
        int dif;
        string t, a, b;
        a = fib[i - 1];
        b = fib[i - 2];

        dif = a.size() - b.size();
        while(dif--){
            t.push_back('0');
        }
        t = t + b;
        b = t;

        int s, carry = 0, in;
        string sum;

        for(in = a.size() - 1; in >= 0; in--){
            s = (a[in] - '0') + (b[in] - '0') + carry;
            carry = s / 10;
            s = s % 10;
            sum.push_back(s + 48);
        }
        if(carry > 0)
            sum.push_back(carry + 48);

        reverse(sum.begin(), sum.end());

        fib[i] = sum;
    }
}
int main()
{
   f();
    int n;
    while(scanf("%d",&n) == 1){
    cout << fib[n] << endl;
    }
    return 0;
}

