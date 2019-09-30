#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long ara[35], s = 1, i, j, test, ans, n;

    ara[1] =1;
        ara[2] = 4;
    for(i = 3; i <= 31; i++){
        ara[i] = ara[i - 1] * 2 + 4;
    }

 cin >> test;

 while(test--){
    scanf("%lld", &n);
    /*if(n ==1){
        ans = 1;
    }
    else{
            ans = 0;
        for(i = 2; i <= n; i++){
           // j = (ara[i] / ara[i - 1]);
            ans += ara[i] + (ara[i] % ara[i - 1]);
            //cout << ara[i] << endl;
        }
    }*/
    printf("%lld\n", ara[n]);
 }
 return  0;
}
