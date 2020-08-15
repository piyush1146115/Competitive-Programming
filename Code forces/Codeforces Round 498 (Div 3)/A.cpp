#include<bits/stdc++.h>
using namespace std;
long long ara[1005];

int main()
{
 long long  n;
 cin >> n;

 for(int i = 0; i < n; i++){
    cin >> ara[i];
 }

    for(int i = 0; i < n; i++){
        if(ara[i] % 2 == 0){
            cout << ara[i] -1 << endl;
        }
        else{
            cout << ara[i] << endl;
        }
    }
}
