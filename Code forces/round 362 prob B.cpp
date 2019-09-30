#include<bits/stdc++.h>
using namespace std;
int main()
{
    string s, a,  temp;
    int b , i, j, k;
    cin >> s;
    i = 0;
    while(s[i] != 'e'){
        a.push_back(s[i]);
        i++;
    }
    b = 0;
    i++;
    while(i < s.size()){
        b = (s[i] - '0') + b * 10;
        i++;
    }
    //cout << a << endl;
        int pos , dif;

        for(i = 0; i < a.size(); i++){
            if(a[i] == '.'){
                pos = i;
                break;
            }
        }
        dif = a.size() - 1 - pos;

    if(b >= dif){
            //cout << "oj";
        a.erase(a.begin() + pos);
        if(b > dif){
            dif = b - dif;
            while(dif--){
                temp.push_back('0');
            }
            a += temp;
        }
    }
    else{
        i = pos;
        while(b--){
            swap(a[i], a[i + 1]);
        i++;
        }
               i = a.size() - 1;

            while(a[i] != '.'){
                if(a[i] > '0')
                break;
            a.erase(a.begin() + i);
            i--;
        }
        if(a[i] == '.')
            a.erase(a.begin() + i);

    }

      //cout << a << endl;
    i = 0;
    while(i < a.size() - 1 && a[i] == '0' && a[i+1] != '.'){
        a.erase(a.begin() + i);
    }
    cout << a << endl;

    //cout << b;
}
