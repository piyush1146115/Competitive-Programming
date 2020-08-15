#include<bits/stdc++.h>
using namespace std;
int main()
{
    string a, b, bi1, bi2;
    string z, x;
    int i, j, k, test, num1, num2;
    char c;

    cin >> test;

    while(test--){
            cin >> a >> c >> b;
        num1 = 0;
        for(i = 0; i < a.size(); i++){
            if(a[i] >= '0' && a[i] <= '9'){
                j = a[i] - 48;
            }
            else
                j = a[i] - 55;

            num1 = j + (num1 * 16);
        }
        num2 = 0;
        for(i = 0; i < b.size(); i++){
            if(b[i] >= '0' && b[i] <= '9'){
                j = b[i] - 48;
            }
            else
                j = b[i] - 55;

            num2 = j + (num2 * 16);
        }
        int res;
        if(c == '+')
            res = num1 + num2;
        else
            res = num1 - num2;

        for(i = 0; i < a.size(); i++){
            if(a[i] >= '0' && a[i] <= '9'){
                j = a[i] - 48;
            }
            else
                j = a[i] - 55;
        int l = 0;
            string z, x;
            while(j != 0){
                    l++;
                k = j % 2;
                j = j / 2;
                //printf("%d\n", k);
                z.push_back(k + 48);
            }
            reverse(z.begin(), z.end());
            while(l != 4){
                x.push_back('0');
                l++;
            }
            bi1 += (x + z);
            x.clear();
            z.clear();
        }
        for(i = 0; i < b.size(); i++){
            if(b[i] >= '0' && b[i] <= '9'){
                j = b[i] - 48;
            }
            else
                j = b[i] - 55;
        int l = 0;

            while(j != 0){
                    l++;
                k = j % 2;
                j = j / 2;
                //printf("%d\n", k);
                z.push_back(k + 48);
            }
            reverse(z.begin(), z.end());
            while(l != 4){
                x.push_back('0');
                l++;
            }
            bi2 += (x + z);
            x.clear();
            z.clear();
        }
        int dif = 13 - bi1.size();
        while(dif--)
            x.push_back('0');

        bi1 = x + bi1;

        x.clear();
               dif = 13 - bi2.size();
        while(dif--)
            x.push_back('0');

            bi2 = x + bi2;
            x.clear();
        cout << bi1 << " " << c << " " << bi2 << " " << "= " << res << endl;
        bi1.clear();
        bi2.clear();
        //printf("%d\n",res);
    }
    return 0;
}
