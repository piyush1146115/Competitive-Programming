#include<bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    int sum, i, j, a, b, count, l;
    double d;

    while(cin >> s){
        if(s[0] == '0'){
            break;
        }
        l = s.size();
        sum = 0;
        for(i = 0; i < l; i++){
            sum += (s[i] - 48);
        }

        if(sum % 9 == 0){
            a = sum;
            count = 1;
                //printf("%d", a);
                while(a != 9 && a > 9){
                    b = 0;

                    while(a != 0){
                        b += a % 10;
                        a = a/ 10;
                    }
                    a = b;
                    count++;
                }


            printf("%s is a multiple of 9 and has 9-degree %d.\n",s.c_str(),count);
        }
        else{
            printf("%s is not a multiple of 9.\n",s.c_str());
        }
    }
    return 0;
}
