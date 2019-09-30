#include<bits/stdc++.h>
using namespace std;
int main()
{
    int i, j, n, test;
    string s;

    cin >> test;

    for(i = 1; i <= test; i++){
        cin >> n >> s;
        int c = 0;
        for(j = 0; j < n; j++){
            if(s[j] == '.'){
                c++;
                j += 2;
            }
        }
        printf("Case %d: %d\n",i, c);
    }
    return 0;
}
