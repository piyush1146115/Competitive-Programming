#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n, h, i , sum = 0;

    cin >> n >> h;

    for(i = 0; i < n; i++){
        int num;
        cin >> num;
        if(num > h)
            sum += 2;
        else
            sum += 1;
    }

    cout << sum << endl;
}
