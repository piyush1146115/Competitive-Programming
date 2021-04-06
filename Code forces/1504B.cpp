#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    int test;
    cin >> test;

    while(test--){
        int n;
        cin >> n;
        vector<int> zero(n + 5, 0);
        string a, b;

        cin >> a >> b;

        if(a[0] == '0')
            zero[0] = 1;

        for(int i = 1; i < n; i++){
            if(a[i] == '0')
                zero[i] = 1;
            
            zero[i] += zero[i - 1];
        }

        int ans = 1, flag = 1, one;

        for(int i = n - 1; i >= 0; i--){
            if(flag == 1){
                if(a[i] != b[i]){
                    one = (i+ 1) - zero[i];
                    if(zero[i] == one){
                        flag = 2;
                    }
                    else{
                        ans = 0;
                        break;
                    }
                }
            }
            else{
                if(a[i] == b[i]){
                    one = (i+ 1) - zero[i];
                    if(zero[i] == one){
                        flag = 1;
                    }
                    else{
                        ans = 0;
                        break;
                    }

                }
            }
        }
        if(ans)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;

    }
}