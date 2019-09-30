#include<bits/stdc++.h>
using namespace std;
int main()
{
    double w;
    int test, i, j, k;
    string s;

    cin >> test;
    getchar();

    for(i = 1; i <= test; i++){
     getline(cin, s);
        k = 1;
        double num[5];
         double a, b;
         a = 0.0;
        b = 0.0;
        for(j = 0; j < s.size(); j++){

            while(s[j] >= '0' && s[j] <= '9' && k)
           {
               a = (s[j] - 48) + a * 10;

               j++;
           }
           k = 0;
        while(s[j] >= '0' && s[j] <= '9' && k == 0)
           {
               b = (s[j] - 48) + b * 10;
               j++;
           }
        }
        // cout << a;
        w = (a * 0.5) + (b * 0.05);

        printf("Case %d: %g\n",i ,w);
    }
    return 0;
}
