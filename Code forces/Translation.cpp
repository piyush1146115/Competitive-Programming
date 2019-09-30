#include<bits/stdc++.h>
using namespace std;
int main()
{
    string a, b;

    cin >> a >> b;
    int  i, j;

    if(a.size() != b.size()){
        printf("NO\n");
    }
    else{
            int l = a.size();
        for(i = 0; i < l; i++){
            if(a[i] != b[l - i - 1])
                break;
        }
        if(i == l)
            printf("YES\n");
        else
            printf("NO\n");
    }
return 0;
}
