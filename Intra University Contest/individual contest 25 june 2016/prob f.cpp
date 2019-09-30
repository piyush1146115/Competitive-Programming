#include<bits/stdc++.h>
using namespace std;
int ara[1005];
int main()
{
    int n, i, j, k, mx =-1;

    cin >> n;

    for(i = 0; i < n ; i++){
        scanf("%d", &k);
        ara[k]++;
        if(ara[k] > mx)
            mx = ara[k];
    }
    int flag = 1;
    if(n % 2 == 0){
        if(mx > n/2)
            flag = 0;
    }
    else{
        if(mx > (n/2 + 1) )
            flag = 0;
    }
    if(flag)
        printf("YES\n");
    else
        printf("NO\n");

}
