#include<bits/stdc++.h>
using namespace std;
int main()
{
    int a, b, x, n;

    cin >> a >> b >> x;

    n = a + b;
    int temp;
    string s;
    if(a >= b){
        temp = 0;
        s = "01";
        x--;
        a--;
        b--;
    }
    else{
        temp = 1;
        s = "10";
        x--;
        a--;
        b--;
    }
    int t = temp;
    for(int i = 0; i < x; i++){
        if(temp == 0){
            a--;
        }
        else{
            b--;
        }
        char ch = (char)(temp + '0');
        temp ^= 1;
        s += ch;
    }

  //  cout << t << " " << a << endl;

    string st = "";

    if(t == 0 ){
        while(a > 0){
            st += '0';
            a--;
        }
    }
    else{
        while(b> 0){
            st += '1';
            b--;
        }
    }
    st = st + s;
    s = st;
    temp ^= 1;

 //   cout << temp << " " << a << endl;
    if(temp == 0 ){
        while(a > 0){
            s += '0';
            a--;
        }
    }
    else{
        while(b> 0){
            s += '1';
            b--;
        }
    }

    st = "";
    if(b > 0){
    b--;
     while(b> 0){
            st += '1';
            b--;
        }

    s[s.size() - 1] = '1';
    s = s + st;
    s.push_back('0');
    }
    else if(a > 0){
     a--;
     while(a> 0){
            st += '0';
            a--;
        }
    s[s.size() - 1] = '0';
    s = s + st;
    s.push_back('1');
    }


    cout << s << endl;
}
