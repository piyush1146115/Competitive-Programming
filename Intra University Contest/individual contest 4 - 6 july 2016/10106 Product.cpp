#include<bits/stdc++.h>
using namespace std;
string sum;

void add(string a, string b)
{
    int dif, s, carry = 0,i, j;
    string temp, res;

    if(a.size() > b.size()){
        dif = a.size() - b.size();
        while(dif--)
            temp.push_back('0');

        temp += b;
        b = temp;
    }
    else if(b.size() > a.size()){
        dif = b.size() - a.size();

        while(dif--)
            temp.push_back('0');
        temp += a;
        a = temp;
    }

    for(i = a.size() - 1; i >= 0 ; i--){
        s = (a[i] - '0') + (b[i] - '0') + carry;
        carry = s / 10;
        s = s % 10;
        res.push_back(s + 48);
    }
    if(carry > 0)
        res.push_back(carry + 48);

    reverse(res.begin(), res.end());

    sum = res;
}

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("ou.txt", "w", stdout);

    string a, b, temp, st[255];
    int i, j, k, l, carry, ans, s;

    while(cin >> a >> b){
            k = b.size() - 1;
            if(a == "0" || b == "0"){
                printf("0\n");
                continue;
            }
        for(i = 0; i < b.size(); i++){
            j = i;
            while(j--)
                temp.push_back('0');

            carry = 0;

            for(j = a.size() - 1; j >= 0; j--){
                s = ((b[k] - 48) * (a[j] - 48)) + carry;
                carry = s / 10;
                s = s % 10;
                st[i].push_back(s + 48);
            }
            if(carry > 0)
                st[i].push_back(carry + 48);

            reverse(st[i].begin(), st[i].end());

            if(temp.size() > 0)
                st[i] += temp;

            temp.clear();
            k--;
        }

        sum = "0";
        for(i = 0; i < b.size(); i++)
            {
                add(sum , st[i]);
            }

        cout << sum << endl;

            for(i = 0; i <= 251; i++)
                st[i].clear();

                sum.clear();
    }
    return 0;
}
