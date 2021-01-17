#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int test;
    cin >> test;

    

    while(test--){
        long long n, Alice = 0, Bob = 0;
        cin >> n;

        vector<long long> v(n+ 2);

        for(int i = 0; i < n; i++){
            cin >> v[i];
        }

        sort(v.rbegin(), v.rend());

        for(int i = 0; i < n; i++){
            if(i % 2 == 0){
                if(v[i] % 2 == 0){
                    Alice += v[i];
                }
            }
            else{
                if(v[i] % 2 == 1){
                    Bob += v[i];
                }
            }
        }

        if(Alice > Bob){
            cout << "Alice" << endl;
        }
        else if(Bob > Alice){
            cout << "Bob" << endl;
        }
        else{
            cout << "Tie" << endl;
        }

    }
}