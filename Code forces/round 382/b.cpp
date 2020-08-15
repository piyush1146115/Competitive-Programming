#include<bits/stdc++.h>
using namespace std;
double ara[100005];
int main()
{
    int i, j, n, k, l;

    cin >> n >> k >> l;

    for(i = 0; i < n; i++){
        scanf("%lf", &ara[i]);
    }

    sort(ara, ara + n);

    if(k > l)
        swap(k , l);

    double sum = 0.0, res;
    for(i = n - 1; i >= (n - k); i--){
        sum += ara[i];
    }



    res = sum / (double)k;
    sum = 0.0;
    for(i = n - k - 1;  i >= (n - k - l); i--)
        sum += ara[i];

    res += (sum / (double)l);

    printf("%.10lf\n", res);
}
