#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long n, x, y, a, b, i;

    cin >> n >> x >> y;

    a = y - n + 1;
    b = y - a;
    if((a * a + b ) >= x && a > 0){
        cout << a << endl;
        for(i = 1; i <= b; i++)
            printf("1\n");
    }
    else
        printf("-1\n");

    return 0;
}
