#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long c, i, j, s, n;

    while(scanf("%lld", &n) == 1 && n != 0){
        s = 3;
        c = 0;
        for(i = 1; i < n - 1; i++){
            for(j = i + 1; j < n ; j++){

                if(s > n)
                    break;
                    c++;
            }
        }
        cout << c << endl;
    }
}
