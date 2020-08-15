#include<bits/stdc++.h>
using namespace std;
int sq[10005];
string  d4[105], d6[1005], d8[10005];
string a2[5], a4[10], a6[100], a8[100];
int ind2 = 3, ind4, ind6, ind8;
void square()
{
    for(int i = 0; i <= 10002; i++){
        sq[i] = i * i;
    }
}
void digit2()
{
    a2[0] = "00";
    a2[1] = "01";
    a2[2] = "81";
}

void digit4()
{
    a4[0] = "0000";
    a4[1] = "0001";
    int i, j, k;
    ind4 = 2;
    string temp, st;
    for(i = 2; sq[i]  <= 10000; i++ ){
        j = sq[i];

        while(j != 0){
            st.push_back((j % 10) + 48);
            j = j / 10;
        }
        int dif = 4 - st.size();
        //cout << st.size() << endl;
        reverse(st.begin(), st.end());
          for(k = 0; k < dif; k++){
            temp.push_back(0 + 48);
          }
        if(dif > 0){
        temp = temp + st;
        st = temp;
        }
        // cout << st <<endl;

        int sum1 = 0, sum2 = 0, sum;

        for(k = 0; k < 2; k++)
            sum1 = (st[k] - 48) + sum1 * 10;

        for(k = 2; k < 4; k++)
            sum2 = (st[k] - 48) + sum2 * 10;

        sum = sum1 + sum2;

        if(sum * sum == sq[i]){
                //cout << st << endl;
            a4[ind4++] = st;
        }

        st.clear();
        temp.clear();

    }
}

void digit6()
{
    a6[0] = "000000";
    a6[1] = "000001";
    int i, j, k;
    ind6 = 2;
    string temp, st;
    for(i = 2; sq[i]  <= 1000000; i++ ){
        j = sq[i];

        while(j != 0){
            st.push_back((j % 10) + 48);
            j = j / 10;
        }
        int dif = 6 - st.size();
        //cout << st.size() << endl;
        reverse(st.begin(), st.end());
          for(k = 0; k < dif; k++){
            temp.push_back(0 + 48);
          }
        if(dif > 0){
        temp = temp + st;
        st = temp;
        }
        // cout << st <<endl;

        int sum1 = 0, sum2 = 0, sum;

        for(k = 0; k < 3; k++)
            sum1 = (st[k] - 48) + sum1 * 10;

        for(k = 3; k < 6; k++)
            sum2 = (st[k] - 48) + sum2 * 10;

        sum = sum1 + sum2;

        if(sum * sum == sq[i]){
                //cout << st << endl;
            a6[ind6++] = st;
        }

        st.clear();
        temp.clear();

    }
}

void digit8()
{
    a8[0] = "00000000";
    a8[1] = "00000001";
    int i, j, k;
    ind8 = 2;
    string temp, st;
    for(i = 2; sq[i]  <= 100000000; i++ ){
        j = sq[i];

        while(j != 0){
            st.push_back((j % 10) + 48);
            j = j / 10;
        }
        int dif = 8 - st.size();
        //cout << st.size() << endl;
        reverse(st.begin(), st.end());
          for(k = 0; k < dif; k++){
            temp.push_back(0 + 48);
          }
        if(dif > 0){
        temp = temp + st;
        st = temp;
        }
        // cout << st <<endl;

        int sum1 = 0, sum2 = 0, sum;

        for(k = 0; k < 4; k++)
            sum1 = (st[k] - 48) + sum1 * 10;

        for(k = 4; k < 8; k++)
            sum2 = (st[k] - 48) + sum2 * 10;

        sum = sum1 + sum2;

        if(sum * sum == sq[i]){
                //cout << st << endl;
            a8[ind8++] = st;
        }

        st.clear();
        temp.clear();

    }
}

int main()
{
    square();
    digit2();
    digit4();
    digit6();
    digit8();

    int i, n;
    while(cin >> n){
    if(n == 2){
    for(i = 0; i < ind2; i++)
        cout << a2[i] << endl;
    }

     if(n == 4){
    for(i = 0; i < ind4; i++)
        cout << a4[i] << endl;
    }

        if(n == 6){
    for(i = 0; i < ind6; i++)
        cout << a6[i] << endl;
    }

     if(n == 8){
    for(i = 0; i < ind8; i++)
        cout << a8[i] << endl;
    }
    }
    return 0;
}
