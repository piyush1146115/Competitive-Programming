#include<bits/stdc++.h>
using namespace std;
int main()
{
   long long  int m1[6], m2[6];
    long long int a, b, i, diva, divb, moda, modb;

    cin >> a >> b;
    diva = a / 5;
    divb = b / 5;

    moda = a % 5;
    modb = b % 5;

    for(i = 0; i < 5; i++){
        m1[i] = diva;
    }
    for(i = 0; i < 5; i++){
        m2[i] = divb;
    }
    for(i = 1; i <= moda; i++){
        m1[i]++;
    }
    for(i = 1; i <= modb; i++){
        m2[i]++;
    }

   long long int sum = 0;
    for(i = 1; i < 5; i++){

        sum += (m1[i] * m2[5 - i]);

    }
    sum += (m1[0] * m2[0]);
   /* for(i = 1; i < 5; i++){
        sum += (m2[i] * m1[5 - i]);
    }*/

    cout << sum << endl;
}
