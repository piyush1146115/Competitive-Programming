#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    string s;

    cin >> n >>  s;

    int A= 0, I = 0;

    for(int i = 0; i < n; i++){
        if(s[i] == 'A'){
            A++;
        }
        else if(s[i] == 'I'){
            I++;
        }
    }
    int ans = 0;

    if(I >= 2){
        ans = 0;
    }
    else if(I == 1){
        ans = 1;
    }
    else{
        ans = A;
    }

    cout << ans << endl;
}
