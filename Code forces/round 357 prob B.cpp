#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long n, i, j, flag = 0, dif;

    cin >> n;

    for(i = 0 ; i < n; i++){
        for(j = 0; j < n; j++){
            dif = n - ((i * 1234567) + (j * 123456));
            //cout << dif << endl;
            if(dif < 0)
                break;

            if(dif % 1234 == 0)
            {
                flag = 1;
                break;
            }
        }
        if(flag == 1 || (i * 1234567 > n))
            break;
    }

    if(flag)
        printf("YES\n");
    else
        printf("NO\n");

}
