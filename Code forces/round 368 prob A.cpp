#include<bits/stdc++.h>
using namespace std;
int main()
{
    int m, n, k, i;
    string s;

    scanf("%d %d", &m, &n);

    k = m * n;
    int flag = 0;
    for(i = 0; i < k; i++){
        cin >> s;
        if(s == "Y" || s == "C" || s == "M")
        {
            flag = 1;
        }
    }

    if(flag)
        printf("#Color\n");
    else
        printf("#Black&White\n");

    return 0;
}
