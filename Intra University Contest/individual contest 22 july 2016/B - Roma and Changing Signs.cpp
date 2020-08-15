#include<bits/stdc++.h>
using namespace std;
int ar[1000000];
int main()
{
    int n, k, i, sum = 0;

    scanf("%d %d", &n, &k);

    for(i = 0; i < n; i++){
        scanf("%d",&ar[i]);
        if(k > 0){
            if(ar[i] < 0){
                ar[i] *= -1;
                k--;
            }
        }
    }

    if(k > 0){
    sort(ar, ar + n);
    if(k % 2 == 1){
        ar[0] *= -1;
    }
    }

    for(i = 0; i < n; i++)
        sum += ar[i];

        printf("%d\n",sum);
}
