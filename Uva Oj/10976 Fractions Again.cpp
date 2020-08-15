#include<bits/stdc++.h>
using namespace std;

int gcd(int a, int b)
{
 if(b == 0)
    return a;
 else return gcd(b, a % b);
}

int lcf(int a, int b)
{
    int ans , mul;

    mul = a * b;
    ans = mul / gcd(a, b);

    return ans;
}

int main()
{
    int n, i, j, lc, t1, t2;
    vector <int> v[3];

    while(scanf("%d",&n) == 1){

        for(i = n + 1; i <= n*2; i++){
            lc = lcf(n, i);
            t1 = lc / n;
            t2 = lc / i;
            int dif, temp;
            dif = t1 - t2;
            j = gcd(dif, lc);
            if(j == dif){
                v[0].push_back(lc/j);
                v[1].push_back(i);
            }
        }

        printf("%d\n",v[0].size());

        for(i = 0; i < v[0].size(); i++){
            printf("1/%d = 1/%d + 1/%d\n",n, v[0][i], v[1][i]);
        }

        v[0].clear();
        v[1].clear();
    }
    return 0;
}
