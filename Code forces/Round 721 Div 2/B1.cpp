#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int test;
    cin >> test;

    while(test--){
        int zero = 0;
        int n;
        cin >> n;
        string s;
        cin >> s;

        for(int i = 0; i < n; i++){
            if(s[i] == '0'){
                zero++;
            }
        }

        if(zero == 0){
            cout << "DRAW" << endl;
        }
        else if(zero % 2 == 1 && zero > 1){
            cout << "ALICE" << endl;
        }
        else{
            cout << "BOB" << endl;
        }

    }
}
