#include<bits/stdc++.h>
using namespace std;
int main()
{
    string a, b, sum, t;
    int test, i, j, dif;

    scanf("%d", &test);

    while(test--){
        cin >> a >> b;
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());
        i = 0;
         while(a[i] == '0'){
                a.erase(a.begin() + i);
                i = 0;
            }

        i = 0;
         while(b[i] == '0'){
                b.erase(b.begin() + i);
                i = 0;
            }

        if(a.size() < b.size())
            swap(a, b);

        dif = a.size() - b.size();
        while(dif--){
            t.push_back('0');
        }
        t = t + b;
        b = t;

        int s, carry = 0, in;

        for(in = a.size() - 1; in >= 0; in--){
            s = (a[in] - '0') + (b[in] - '0') + carry;
            carry = s / 10;
            s = s % 10;
            sum.push_back(s + 48);
        }
        if(carry > 0)
            sum.push_back(carry + 48);

            i = 0;
            while(sum[i] == '0'){
                sum.erase(sum.begin() + i);
                i = 0;
            }

        cout << sum << endl;
        sum.clear();
        t.clear();
    }
}
