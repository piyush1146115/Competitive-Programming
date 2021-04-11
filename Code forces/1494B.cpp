#include<bits/stdc++.h>
using namespace std;
int main()
{
    int test;

    cin >> test;

    while(test--){
        int n, U, R, D, L;

        cin >> n >> U >> R >> D >> L;

        string ans = "NO";

        for(int i = 0; i < 16; i++){
            int NU = U;
            int NR = R;
            int ND = D;
            int NL = L;

            if(i & 1){
                NU--;
                NL--;
            }
            if(i & 2){
                NU--;
                NR--;
            }
            if(i & 4){
                ND--;
                NR--;
            }
            if(i & 8){
                ND--;
                NL--;
            }

            if(ND >= 0 && NL >= 0 && NR >= 0 && NU >= 0){
                if(ND <= (n - 2) && NL <= (n - 2) && NR <= (n - 2) && NU <= (n -2)){
                    ans = "YES";
                    break;
                }
            }
        }

        cout << ans << endl;
    }
}
