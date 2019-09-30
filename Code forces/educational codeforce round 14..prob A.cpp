#include<bits/stdc++.h>
using namespace std;
int main()
{
    int i, j, n, c = 0;

    cin >> n;

    for(i = 0; i < n; i++){
        scanf("%d", &j);
        if(j == 0)
            c++;
    }
    if(n == 1){
        if(j)
            printf("YES\n");
        else
            printf("NO\n");
    }
    else{
        if(c == 1)
            printf("YES\n");
        else
            printf("NO\n");
    }

}
