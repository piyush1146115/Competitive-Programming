#include<bits/stdc++.h>
using namespace std;
int main()
{
     long long int n, d, test, i, s = 0;
    int t = 0;
    //cin >> test;
    while(cin >> n && n != 0){
        t++;
        for(i = 1; i <= n; i++){
            s = ((i * (i - 1))/ 2) - i;
            //cout << s << endl;
            if(s >= n)
                break;
        }
        cout <<"Case " << t <<": "<< i << endl;
    }
    return 0;
}
