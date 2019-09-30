#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long int n, b, d, i, j, k, sum;

    scanf("%I64d %I64d %I64d",&n, &b, &d);
    sum = 0;
    int co = 0;
    for(i = 0; i < n; i++){
            scanf("%I64d", &k);
            if(k > b)
            continue;

        sum += k;
        if(sum > d)
        {
            co++;
            sum = 0;
        }
    }

    cout << co << endl;
    return 0;
}
