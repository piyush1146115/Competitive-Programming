#include<bits/stdc++.h>
using namespace std;
int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int a, b, test, cse = 0, s1, s2, sum, len, i, s3;
    char k1[200], k2[200];

    cin >> test;

    while(test--){
        cse++;
        scanf("%d %s %s",&len, k1, k2);
        sum = 0;
        for(i = 0; i < len; i++){
            a = k1[i] - '0';
            b = k2[i] - '0';


            s1 = fabs(b - a);
            s2 = a + (9 - b) + 1;
            s3 = (9 - a) + b + 1;
            s2 = min(s2, s3);
            sum += min(s1, s2);
        }
        printf("Case %d: %d\n",cse, sum);
    }
    return 0;
}
