#include<bits/stdc++.h>
using namespace std;
int main()
{
    double n,st, ol;

    while(scanf("%lf",&n)  == 1){
            st = 0;
            ol = 0;
        while(n > 0){
            n = n / 9.0;
            if(n <= 1){
                st = 1;
                break;
            }
            n = n / 2.0;
            //cout << n << endl;
            if(n <= 1){
                ol = 1;
                break;
            }
        }
    if(st == 1)
    printf("Stan wins.\n");
    else
        printf("Ollie wins.\n");
    }
    return 0;
}
