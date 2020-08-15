#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long ara[100010], n, h, k, i, j;

    cin >> n >> h >> k;

    for(i = 0; i < n ; i++)
        scanf("%lld",&ara[i]);

    long long sum = 0, sec = 0;

    for(i = 0; i < n; i++){
        sum += ara[i];
                j = i + 1;
               while(j < n){
                if(sum + ara[j] <= h){
                    sum += ara[j];
                    j++;
                    i++;
                }
                else
                    break;
            }


       sec += (sum / k);
       long long int div = sum / k;
        sum -=  (k * div);
        //printf("%lld %lld\n", sum, sec);

       if(sum % k > 0 ){
        if(i == n -1)
        sec++;
       else if(sum + ara[i + 1] > h){
        sec++;
        sum = 0;
       }
       else
        sum = sum % k;
       }
    }
    cout << sec << endl;
}
