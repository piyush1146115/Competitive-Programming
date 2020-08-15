#include<bits/stdc++.h>
using namespace std;
int main()
{
    unsigned long long ans = 0, temp, n, i, j, k, l;
    char ch;

    cin >> n >> ch;

    k = n /4;
    if(n % 4 == 0)
        k--;

    ans =   (k * 14) + (k * 2);

    if(n % 2 == 0){
        ans += 7;
    }

        //ans +=  (k * 6);

    if(ch == 'f')
        ans += 1;
    else if(ch == 'e')
        ans += 2;
    else if(ch == 'd')
        ans += 3;
    else if(ch == 'a')
        ans += 4;
    else if(ch == 'b')
        ans += 5;
    else
        ans += 6;


    cout << ans << endl;
}
