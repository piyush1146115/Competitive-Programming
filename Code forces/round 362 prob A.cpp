#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long s, t, d, rem, dif;

    cin >> s >> t >> d;

    dif = d - s;

    if(dif < t){
        if(dif == 0){
            printf("YES\n");
        }
        else{
            printf("NO\n");
        }
    }
    else{
    rem = dif % t;

    if(rem == 0 || rem == 1)
        printf("YES\n");
    else
        printf("NO\n");
    }
    return 0;
}
