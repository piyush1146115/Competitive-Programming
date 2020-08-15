#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n, k;

    cin >> n >> k;

    int m = 240 - k, c= 0, t = 0;

    for(int i = 1; i <= n; i++){
        t += i * 5;

        if(t <= m){
            c++;
        }
        else
            break;
    }
    cout << c << endl;
}
