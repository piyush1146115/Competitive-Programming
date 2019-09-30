#include<bits/stdc++.h>
using namespace std;
int main()
{
    string in, sum = "0", a, b;
    int i, j, dif, l;

    while(cin >> in){
        if(in ==  "0")
            break;

        if(sum.size()> in.size()){
            dif = sum.size() - in.size();
            while(dif--)
                a.push_back('0');

            a = a + in;
            in = a;
        }
        else{
                dif = in.size() - sum.size();
                while(dif--)
                    a.push_back('0');

            a = a + sum;
            sum = a;
        }

        int carry = 0, s;

        for(i = in.size() - 1; i >= 0; i--){
            s = (in[i]  - 48) + (sum[i] - 48) + carry;
            carry = s / 10;
            s = s % 10;
            b.push_back(s + 48);
        }
        if(carry > 0)
            b.push_back(carry + 48);

        reverse(b.begin(), b.end());
        sum = b;

        b.clear();
        a.clear();
        in.clear();
    }
    cout << sum << endl;
}
