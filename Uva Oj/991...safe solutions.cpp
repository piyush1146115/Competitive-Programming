#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long int i, j, n, num, den, k, t = 0;

    while(cin >> n){
        if(t == 1){
            printf("\n");
        }
        j = n * 2;
        k = j - n;
        num = 1;
        den = 1;
        if(k > n + 1){
            for(i = j; i > k; i--)
                num *= i;

            for(i = 1; i <= n + 1; i++)
                den *= i;
        }
        else{
               for(i = j; i > n + 1; i--)
                num *= i;

            for(i = 1; i <= k; i++)
                den *= i;
        }
        cout << num / den << endl;
           t = 1;
    }
    return 0;
}
