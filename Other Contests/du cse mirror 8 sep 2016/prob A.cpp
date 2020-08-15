#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long a, b, test;

    cin >> test;

    while(test--){
        cin >> a >> b;

        if(b < a || (b - a > 6)){
           printf("No\n");
           }
           else{
            printf("Yes\n");
           }
    }
    return 0;
}
