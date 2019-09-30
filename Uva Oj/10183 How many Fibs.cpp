#include<bits/stdc++.h>
using namespace std;
   string fib[10005];

void f()
{

    int i, j, k;
    fib[0] = "1";
    fib[1] = "2";

    for(i = 2; i <= 5000; i++){
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


bool isless(string a, string b)
{
    if(a.size() < b.size())
        return true;
    if(a.size() > b.size())
        return false;

    for(int i = 0; i < a.size(); i++){
            int c = a[i] - '0';
            int d = b[i] - '0';
        if(c < d)
            return true;
        if(c > d)
            return false;
    }

    return true;
}


int main()
{
   f();

    string a, b;

    while(cin >> a >> b){
        if(a == "0" && b == "0")
            break;

        if(isless(b, a))
            swap(a, b);

        int cnt = 0;
       // cout << a << " " << b << endl;
        for(int i = 0; i < 5000; i++){
            if(isless(a, fib[i]) && isless(fib[i], b))
                cnt++;
        }


//        for(int i = 0; i < 15; i++)
//            cout << fib[i] << endl;

        printf("%d\n",cnt);
    }
    return 0;
}


