#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    double  k;

    cin >> n >> k;

    k -= .5;

    double total = 0.0, temp;

    for(int i = 0;i < n; i++ ){
        cin >> temp;
        total += temp;
    }

    int cnt = 0;

    double avg = total / (double)n;

    while(avg < k){
        cnt++;
        n++;
        total += (k +.5);
        avg = total / (double)n;
    }

    cout << cnt << endl;
}

