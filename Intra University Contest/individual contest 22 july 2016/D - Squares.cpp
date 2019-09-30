#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long n, k, ar[55], i, j;

    cin >> n >> k;

    for(i = 0; i < n; i++){
        cin >> ar[i];
    }

    sort(ar, ar + n);

    if(k > n){
        printf("-1\n");
    }
    if(k == n){
        printf("%lld 0\n",ar[0]);
    }
    if(k < n){
        j = n - k - 1;
        if(ar[j] + 1 > ar[j + 1]){
            printf("-1\n");
        }
        else{
            printf("%lld 0\n",ar[j] + 1);
        }
    }

    return 0;
}
