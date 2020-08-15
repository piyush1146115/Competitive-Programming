#include<bits/stdc++.h>
using namespace std;
int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    string a, b, c, res;
    int i, j, dif, test, flag;

    cin >> test;

    while(test--){
        cin >> a >> b;
        flag = 0;

        if(a.size() >= b.size()){
        dif = a.length() - b.length();
        while(dif--)
            c.push_back('0');

        c += b;
        b = c;
        c.clear();
        }
        else{
            dif = b.length() - a.length();
            while(dif--)
                c.push_back('0');

            c += a;
            a = c;
            c.clear();
        }
         if(a < b){
            swap(a, b);
            flag = -1;
        }

        //cout << a << endl << b << endl;
        //cout << dif;
        for(i = a.size() - 1; i >= 0; i--){
            if(a[i] >= b[i]){
                res.push_back(a[i] - b[i] + 48);
               // cout << a[i] <<" " << b[i] << endl;
            }
        else{
                res.push_back((a[i] + 10) - b[i] + 48);
                j = i - 1;
                while(b[j] == '9'){
                    b[j] = '0';
                    j--;
                }

                b[j] += 1;
            }
        }

        reverse(res.begin(), res.end());


        if(flag == -1)
            cout << "-";
        flag = 0;
        for(i = 0; i < res.size(); i++){
                if(res[i] != '0')
                    flag = 1;
            if(flag)
                printf("%c",res[i]);
        }
        if(flag == 0)
            printf("0");
        cout << endl;
        res.clear();
    }
    return 0;
}
